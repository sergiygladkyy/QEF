function catalog_Colors_Binding(x)
{

this.object = x;
this.map = x.attributes();
this.code;
this.description;
this.Write = function()
{
this.object.setAttribute("code", this.code);
this.object.setAttribute("description", this.description);
}
this.GetRef = function()
{
return this;
}
this.Safe = function()
{
this.object.setAttribute("code", this.code);
this.object.setAttribute("description", this.description);
this.object.serializeToTheDB();
}
}
