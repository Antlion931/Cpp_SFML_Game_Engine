uniform sampler2D texture;

uniform vec2 cell_size;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    // multiply it by the color
    gl_FragColor = vec4(color_id.x,color_id.y,color_id.z,pixel.a);
}
