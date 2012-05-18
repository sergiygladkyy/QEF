function catalog_Persons_Binding(x)
{

this.object = x;
this.map = x.attributes();
this.age;
this.code;
this.description;
this.f_name;
this.l_name;
this.Write = function()
{
this.object.setAttribute("age", this.age);
this.object.setAttribute("code", this.code);
this.object.setAttribute("description", this.description);
this.object.setAttribute("f_name", this.f_name);
this.object.setAttribute("l_name", this.l_name);
}
this.GetRef = function()
{
return this;
}
this.Safe = function()
{
this.object.setAttribute("age", this.age);
this.object.setAttribute("code", this.code);
this.object.setAttribute("description", this.description);
this.object.setAttribute("f_name", this.f_name);
this.object.setAttribute("l_name", this.l_name);
this.object.serializeToTheDB();
}
}
