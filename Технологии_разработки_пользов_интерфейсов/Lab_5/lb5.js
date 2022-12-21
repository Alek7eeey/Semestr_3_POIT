 // // 1.	Хранилище всего имеющегося товара в интернет-магазине представляет собой объект products. 
// //  Весь товар разделен на категории, одна из них «Обувь», которая в свою очередь делится на виды «Ботинки»,
// //   «Кроссовки», «Сандалии». О каждой паре обуви хранится следующая информация: уникальный номер товара, размер обуви, цвет, цена. 

class Product
{
  constructor(id,number, name, price, size, color, sale = 0) {
    this.sale = 0;
    this.id = id;
    this.type = number;
    this.name = name;
    this.size = size;
    this.color = color;
    this.sale = sale;
    this.startPrice = price;
    this.price = Math.round(price - (price * sale / 100));
  }
  // get color() {
  //   return this.color;
  // }
  // get size() {
  //   return this.size;
  // }
 
}
let products = [
  new Product(1,"Кроссовки", "Nike Air Forse", 150, 42, "black"),
  new Product(2,"Кроссовки", "Addidas 32", 200, 40, "black", 20),
  new Product(3,"Кроссовки", "Boot Sicker", 50, 42, "white"),
];

//Задание_2
class ProductIterator {
  constructor(products) {
      this.index = -1;
      this.products = products;
  }
  next() {
      if (this.index < products.length) {
          return { done: false, value: products[++this.index] };
      }
      else {
          return { done: true, value: null };
      }
  }
}
let iterator = new ProductIterator(products);
let prod=iterator.next();
console.log('---------------------------------------------------');
while(prod.done==false){
  console.log(prod.value);
  prod=iterator.next();
}

// 3.	Реализуйте фильтр обуви по цене в заданном диапазоне, по заданному размеру, по заданному цвету. Выведите номера товаров, соответствующих заданному условию (фильтру).

function filtreByPrice() {
  var priceFrom = Number(100);
  var priceTo = Number(210);
  let set = new Set();

  let arr = products.filter((value) => value.price >= priceFrom &&
      value.price <= priceTo);
      console.log('Сортировка по цене: ');
  arr.forEach(element => {
    console.log('id: '+ element.id);
    console.log('Mark: '+ element.name);
    console.log('Price: '+ element.price);
  }); 

  arr.forEach((value) => set.add(value));
  return set;
}

function filtreByColor() {

  let color = "black";
  let set = new Set();
  let arr = products.filter((value) => value.color == color);
  console.log('Сортировка по цвету: ');
  arr.forEach(element => {
    console.log('id: '+ element.id);
    console.log('Mark: '+ element.name);
    console.log('Color: '+ element.color);
  }); 
  arr.forEach((value) => set.add(value));
  return set;
}

function filtreBySize() {

  let size = Number(42);

  let set = new Set();
  let arr = products.filter((value) => value.size = size);
  console.log('Сортировка по размеру: ');
  arr.forEach(element => {
    console.log('id: '+ element.id);
    console.log('Mark: '+ element.name);
    console.log('Size: '+ element.size);
  }); 
  arr.forEach((value) => set.add(value));
  return set;
}

filtreBySize();
filtreByColor();
filtreByPrice();

// 4.	Каждый товар (пара обуви) из предыдущей задачи представляет собой однотипные объекты. Учитывая это, создайте объект товара с
// помощью new, при этом свойства «id», «цвет» и «размер» 
//должны быть доступны только для чтения, свойство «id» не может быть удалено. 

Object.defineProperty(products, "name", { //только для чтения
  writable: false
});
Object.defineProperty(products, "size", { //только для чтения
  writable: false,
  enumerable: true,
  configurable: true
});
Object.defineProperty(products, "id", { //нельзя удалить 
  writable: false,
  enumerable: true,
  configurable: false
});


// 5.	Добавьте в описание товара новые свойства: «скидка» и «конечная стоимость» (стоимость с учетом скидки). Добавьте геттер и сеттер для свойства «конечная стоимость», учитывая то, что свойства «скидка» и «конечная стоимость» взаимозависимые.
let shoes7 = new Product("boots", "ботинки", 7, 42, "red", 3000, 300);
            Object.defineProperty(shoes7, "id", {writable: false});
            Object.defineProperty(shoes7, "color", {writable: false});
            Object.defineProperty(shoes7, "size", {writable: false});
            Object.defineProperty(shoes7, "id", {configurable: false});

            shoes7.color = "blue";
            shoes7.id = 9;


Object.defineProperty(shoes7, "finalCost", {

  get: function() {
    return this.cost - this.discont;
  },

  set: function(value) {
      
    }
});

console.log(shoes7.finalCost);