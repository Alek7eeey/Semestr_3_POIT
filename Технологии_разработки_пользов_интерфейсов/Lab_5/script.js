function Product(type, name, id, size, color, cost, discont)
{
    this.type = type,
    this.name = name,
    this.id = id,
    this.size = size
    this.color = color,
    this.cost = cost,
    this.discont = discont,
    this.finalCost
}

let pr1 = new Product("Boots" ,"Nike Air Forse", 1, 39, "black", 3000, 300);
let pr2 = new Product( "Sneakers" ,"Addidas 32", 2, 39, "white", 3200, 200);
let pr3 = new Product("Boots" ,"Boot Sicker", 3, 42, "purple", 4000, 0);
let pr4 = new Product("Sneakers","Nike Morse", 4, 41, "green", 2500, 0);
let pr5 = new Product("Sandals","SandalsUSSR", 5, 38, "black", 1000, 0);

let products = { shoes: [ pr1, pr2, pr3, pr4, pr5] }

//итератор
class ProductIterator {
  constructor(products) {
      this.index = -1;
      this.products = products
  }
  next() {
      if (this.index < products.shoes.length) {
          return { done: false, value: products.shoes[++this.index] };
      }
      else {
          return { done: true, value: null };
      }
  }
}

let iterator = new ProductIterator(products);
let prod=iterator.next();
console.log('------------------------------------------------');
while(prod.done==false)
{
  console.log(prod.value);
  prod=iterator.next();
}

console.log('Сортировка по стоимости:');
    for(let sho of products.shoes)
    {
      if(sho.cost > 3000)
      {
          console.log(sho.type + " " +  sho.name + " " +  sho.color + " " + sho.id + " " + sho.size  + " " + sho.cost);
      }
    }
    
    console.log('Сортировка по цвету:');
    for(let sho of products.shoes)
    {
      if(sho.color == "black")
      {
          console.log(sho.type + " " +  sho.name + " " +  sho.color + " " + sho.id + " " + sho.size  + " " + sho.cost);
      }
    }

    console.log('Сортировка по размеру:');
    for(let sho of products.shoes)
    {
      if(sho.size == 41)
      {
          console.log(sho.type + " " +  sho.name + " " +  sho.color + " " + sho.id + " " + sho.size  + " " + sho.cost);
      }
    }


    let shoes7 = new Product("boots", "nike mercury", 7, 42, "red", 3000, 300);
    Object.defineProperty(shoes7, "id", {writable: false});
    Object.defineProperty(shoes7, "color", {writable: false});
    Object.defineProperty(shoes7, "size", {writable: false});
    Object.defineProperty(shoes7, "id", {configurable: false});

    shoes7.color = "green";
    shoes7.id = 9;
    console.log('Добавление id и цвета:');
    console.log(shoes7.color +" " + shoes7.id);

    console.log('Стоимость с учётом скидки:');
    Object.defineProperty(shoes7, "finalCost", {

        get: function() {
          return this.cost - this.discont;
        },
      
        set: function(value) {
            
          }
      });

    console.log(shoes7.finalCost);
    
  
    

