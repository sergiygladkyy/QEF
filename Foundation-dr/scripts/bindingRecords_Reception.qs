function register_Records_Reception_Binding(x)
{

this.object = x;
this.map = x.attributes();
this.age;
this.country;
this.l_name;
this.s_name;
this.Write = function()
{
this.object.setAttribute("age", this.age);
this.object.setAttribute("country", this.country);
this.object.setAttribute("l_name", this.l_name);
this.object.setAttribute("s_name", this.s_name);
}
this.Add = function()
{
this.object.setAttribute("age", "");
this.object.setAttribute("country", "");
this.object.setAttribute("l_name", "");
this.object.setAttribute("s_name", "");
return this;
}
}
