attribute vec4 position;
attribute vec3 normal;

varying vec2 texcoord0;
varying vec2 texcoord1;

uniform mat4 modelViewMatrix;
uniform float time;

const vec3 falloff = vec3(1.0, 0.05, 0.003);

vec3 trans(vec3 pos) {
    return (modelViewMatrix * vec4(pos, 1.0)).xyz;
}

vec3 point_light(
                 const vec3 color,
                 const vec3 light_position,
                 const vec3 current_position,
                 const vec3 normal,
                 const vec3 k
                 ) {
    float dist = distance(light_position, current_position);
    float attenuation = 1.0 / (k.x+(k.y*dist)+(k.z*dist*dist));
    
    return color * attenuation * max(dot(normal, normalize(current_position - light_position)), 0.0);
}



void main(){
    
    vec4 vert = gl_Vertex;
    
//    vert.xyz += gl_Normal * 100.0;
    gl_Position = gl_ModelViewProjectionMatrix * vert;
    gl_TexCoord[0] = gl_MultiTexCoord0;
    // transform texcoords
    texcoord0 = vec2(gl_TextureMatrix[0] * gl_MultiTexCoord0);
	texcoord1 = vec2(gl_TextureMatrix[1] * gl_MultiTexCoord0);
    
//    vLightWeighting = vec3(0.1,0.1,0.1) +
//                point_light(vec3(1.0), vec3(0.25,-1.0,0.25), trans(gl_Vertex.xyz), gl_Normal, falloff)*1.5 +
//                point_light(vec3(1.0), vec3(-1.25,1.0,-2.25), trans(gl_Vertex.xyz), gl_Normal, falloff)*1.5;
}
