#version 330 core
out vec4 FragColor;

//struct Material {
//    sampler2D diffuse;
//    vec3 specular;    
//    float shininess;
//}; 

//struct Light {
//    vec3 position;
//    vec3 ambient;
//    vec3 diffuse;
//    vec3 specular;
//};

//in vec3 FragPos;  
//in vec3 Normal;  
//in vec2 TexCoords;
//in vec4 FragPosLightSpace;

in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    //vec4 FragPosLightSpace;
} fs_in;

//uniform vec3 viewPos;
uniform sampler2D texture1;
//uniform Material material;
//uniform Light light;
//uniform sampler2D shadowMap;

void main()
{
    // ambient
    FragColor = texture(texture1, fs_in.TexCoords);
    //FragColor = vec4(0,1,1,1);
    //FragColor = texColor;
} 