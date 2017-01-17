varying vec2 texcoord0;
varying vec2 texcoord1;
uniform sampler2D tex0;
uniform float ring;
uniform float ringDiv;
uniform vec2 mouse;

void main(){
    vec2 uv = texcoord0;
    float r = distance(uv , vec2(mouse));
//    float ring = 70.0;
    float rr = fract(r*ring)/ringDiv;
    r = floor(r*ring)/ringDiv;
    uv = -1.0 + 2.0 * uv;
    
    uv *= ( rr);
    uv = uv * 0.5 + 0.5;

    gl_FragColor = texture2D(tex0, uv);
}
