uniform sampler2D texture;

uniform vec2 lightPos;
uniform float radius;
uniform float intensity;

void main()
{
    vec2 uv = gl_TexCoord[0].xy;
    vec4 color = texture2D(texture, uv);

    float dist = distance(gl_FragCoord.xy, lightPos);

    float light = 1.0 - smoothstep(0.0, radius, dist);

    vec3 torchColor = vec3(1.0, 0.9, 0.6);

    color.rgb += torchColor * light * intensity;

    gl_FragColor = color;
}