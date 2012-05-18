function document_Car_order_Binding(x)
{

this.object = x;
this.datetime;
this.model;
this.number;
this.price;
this.year;
this.Write = function()
{
this.object.setAttribute("datetime", this.datetime);
this.object.setAttribute("model", this.model);
this.object.setAttribute("number", this.number);
this.object.setAttribute("price", this.price);
this.object.setAttribute("year", this.year);
}
this.Add = function()
{
this.object.setAttribute("datetime", "");
this.object.setAttribute("model", "");
this.object.setAttribute("number", "");
this.object.setAttribute("price", "");
this.object.setAttribute("year", "");
return this;
}
}
