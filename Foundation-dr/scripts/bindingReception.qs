function document_Reception_Binding(x)
{

this.object = x;
this.age;
this.country;
this.datetime;
this.l_name;
this.number;
this.s_name;
this.Write = function()
{
this.object.setAttribute("age", this.age);
this.object.setAttribute("country", this.country);
this.object.setAttribute("datetime", this.datetime);
this.object.setAttribute("l_name", this.l_name);
this.object.setAttribute("number", this.number);
this.object.setAttribute("s_name", this.s_name);
}
this.Add = function()
{
this.object.setAttribute("age", "");
this.object.setAttribute("country", "");
this.object.setAttribute("datetime", "");
this.object.setAttribute("l_name", "");
this.object.setAttribute("number", "");
this.object.setAttribute("s_name", "");
return this;
}
}
