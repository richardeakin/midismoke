#version 440

precision highp float;

in float v_layer;

uniform vec3 u_resolution;

uniform vec3 u_position;
uniform vec4 u_value;
uniform float u_radius;

out vec4 oFragColor;

void main () {
	vec3 coordinates = vec3(gl_FragCoord.xy, v_layer);
	float dist = distance(coordinates, u_position);
	vec4 scaledValue = max(1.0 - dist / u_radius, 0.0) * u_value;
	oFragColor = scaledValue;
};
