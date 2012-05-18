function catalogs_Binding()
{
this.Persons = new catalog_Persons_Binding (Persons);
this.Colors = new catalog_Colors_Binding (Colors);
}
var Catalogs = new catalogs_Binding();
