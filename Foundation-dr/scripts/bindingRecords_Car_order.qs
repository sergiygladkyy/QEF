function register_Records_Car_order_Binding(x)
{

this.object = x;
this.map = x.attributes();
this.model;
this.price;
this.year;
this.Write = function()
{
this.object.setAttribute("model", this.model);
this.object.setAttribute("price", this.price);
this.object.setAttribute("year", this.year);
}
this.Add = function()
{
this.object.setAttribute("model", "");
this.object.setAttribute("price", "");
this.object.setAttribute("year", "");
return this;
}
}
