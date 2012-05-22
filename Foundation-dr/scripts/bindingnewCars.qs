function catalog_newCars_Binding(x)
{

this.object = x;
this.map = x.attributes();
this.code;
this.description;
this.year_of_production;
this.Write = function()
{
this.object.setAttribute("code", this.code);
this.object.setAttribute("description", this.description);
this.object.setAttribute("year_of_production", this.year_of_production);
}
this.GetRef = function()
{
return this;
}
this.Safe = function()
{
this.object.setAttribute("code", this.code);
this.object.setAttribute("description", this.description);
this.object.setAttribute("year_of_production", this.year_of_production);
this.object.serializeToTheDB();
}
}
