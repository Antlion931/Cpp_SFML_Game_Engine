uniform sampler2D texture;
uniform vec2 u_resolution;

void main()
{
    // lookup the pixel in the texture
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    vec2 uv = gl_FragCoord.xy / u_resolution.xy;
    uv *=  1.0 - uv.yx;
    float vig = uv.x*uv.y * 15.0; // multiply with sth for intensity
    
    vig = pow(vig, 0.08); // change pow for modifying the extend of the  vignette

    gl_FragColor = vec4(vig) * gl_Color * pixel; 
}