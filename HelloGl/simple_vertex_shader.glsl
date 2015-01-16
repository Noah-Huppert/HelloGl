void main(){
	vec4 a = gl_Vertex;
	a.x = a.x * 2;

	gl_Position = gl_ModelViewProjectionMatrix * a;
}