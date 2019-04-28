#version 320 es

layout (location = 0) in highp vec4 in_position;
layout (location = 1) in lowp vec4 in_color;

layout(location = 0) uniform mat4 mvp;

out lowp vec4 color;

void main()
{
	gl_Position = mvp * in_position;
	color = in_color;
}
