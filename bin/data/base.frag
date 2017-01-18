varying vec2 texcoord0;
varying vec2 texcoord1;
uniform sampler2D tex0;
uniform float ring;
uniform float ringDiv;
uniform vec2 mouse;
uniform float time;

const float B = 0.005;
void main(){
    vec2 uv = texcoord0;
    
    float r = distance( vec2(uv.x * 0.8, uv.y) , vec2(mouse));
    float dist = r;
    float conv = ring;
    float v = dist*conv - time*0.1;
    float ringr = floor(v);
    
//    float ring = 70.0;
//    float rr = fract(r*ring)/ringDiv;
    r = floor(r*ring);
    
    float color = smoothstep(-B, B, abs(dist - (ringr + float(fract(v)>0.5))/conv));
    float c = color;
//    color = 1.0 - color;
    color = clamp(color, 0.0,1.0);
    color *= 0.02;
    color += (ringr/ringDiv);
//    color += (ringr/ringDiv);
//    color *= (ringr/ringDiv);
//    if(mod(ringr,2.)==1.)
//        color=1.-color;
//    vec4 fun = vec4(vec3(r/ringDiv),1.0 -c);
    
    uv = -1.0 + 2.0 * uv;
    uv *= r;//mod( color,1.0);
    uv = uv * 0.5 + 0.5;
    vec4 t = texture2D(tex0, uv);
    
//    float circ = distance(uv, vec2(mouse));
//    circ += mod(time*0.005, 1.0);
//    circ = floor(circ + 0.5);
//    
   
    
    gl_FragColor = t;
//    gl_FragColor.a = color;
}
