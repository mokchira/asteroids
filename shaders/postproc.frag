#version 460

layout(location = 0) out vec4 outColor;

layout(set = 0, binding = 0) uniform sampler2D inTex;

#define KERN_SIZE 7
#define KERN_WIDTH 3
#define KERN_LEN 49

float glow[KERN_LEN] = {
    -0.212183, -0.030157, 0.096492, 0.142857, 0.096492, -0.030157, -0.212183, 
    -0.030157, 0.191878, 0.361123, 0.428571, 0.361123, 0.191878, -0.030157, 
    0.096492, 0.361123, 0.595939, 0.714286, 0.595939, 0.361123, 0.096492, 
    0.142857, 0.428571, 0.714286, 1.000000, 0.714286, 0.428571, 0.142857, 
    0.096492, 0.361123, 0.595939, 0.714286, 0.595939, 0.361123, 0.096492, 
    -0.030157, 0.191878, 0.361123, 0.428571, 0.361123, 0.191878, -0.030157, 
    -0.212183, -0.030157, 0.096492, 0.142857, 0.096492, -0.030157, -0.212183, 
};

void main()
{
    vec2 uv =  gl_FragCoord.xy; // this works because our sampler is set to use unnormalizedCoordinates
    vec4 baseColor = vec4(0, 0, 0, 0);
    for (int i = -KERN_WIDTH; i <= KERN_WIDTH; i++)
    {
        for (int j = -KERN_WIDTH; j <= KERN_WIDTH; j++)
        {
            const float scale = glow[(i+1) * KERN_SIZE + (j + 1)];
            const vec2  delta = vec2(i, j);
            baseColor += scale * texture(inTex, uv + delta);
        }
    }
    outColor = baseColor;
}
