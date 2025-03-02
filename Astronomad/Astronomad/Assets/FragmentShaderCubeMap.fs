#version 450 core

in vec3 fragTexCoord;

out vec4 color;
uniform samplerCube cubeSampler;

void main(void)
{
	color = texture(cubeSampler, fragTexCoord).rgba;
}