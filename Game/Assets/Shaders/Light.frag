uniform sampler2D texture;

uniform vec2 lightPos;
uniform vec2 lightDir;      // direction (normalisée)
uniform float coneAngle;
uniform float maxDistance;  // portée de la flashlight

void main()
{
    // "720" ça correspond à la hauteur de l'écran. 
    // On peut en faire une variable en paramètre mais bon.. flemme.

    vec2 pixelPos = vec2(gl_FragCoord.x, 720.0 - gl_FragCoord.y);
    vec2 toPixel = pixelPos - lightPos;
    vec2 dir = normalize(toPixel);

    float distance = length(toPixel);

    float angle = dot(dir, lightDir);
    float cone = smoothstep(cos(coneAngle), 1.0, angle + 2);
    float attenuation = 1.0 - clamp(distance / maxDistance, 0.0, 1.0);
    float light = cone * attenuation;

    vec4 color = texture2D(texture, gl_TexCoord[0].xy);
    color.rgb *= light;
    color.a = 0.45f;
    gl_FragColor = color;
}