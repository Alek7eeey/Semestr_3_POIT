// 1.	Вы – модератор на форуме о собаках. Существуют определённые правила модерации комментариев пользователей: длина комментария не более n символов; 
// запрещается использовать слова с корнем «кот» – он заменяется на символ *; слова с корнем «собак» должны быть с большой буквы; перед словом «пес» обязательно должно
// быть слово «многоуважаемый».
//  Выполните модерацию комментария пользователя и опубликуйте на форуме, правильный комментарий.
// const comment = prompt('Введите комментарий: ');
// let n = 1000;

// if(comment.length<n){

//    var words=comment.split(' ');

//     for (let i=0; i<words.length; i++) {
        
//         if(words[i].indexOf('кот')!=-1||words[i].indexOf('Кот')!=-1){
//             words[i]="*" ;
//         }

//         if(words[i].indexOf('Собак')!=-1||words[i].indexOf('собак')!=-1){
//             words[i]=words[i].toUpperCase();
//         }

//         if(words[i]=="пес"){
//             words[i]="многоуважаемый пес";
//         }
//     } 

//     alert(words.join(' ')); //метод join() объединяет все элементы массива (или массивоподобного объекта) в строку.

// }  else {
//     alert("Длина комментария привышена");
//     }
 
    // 2.	По номеру дня недели определить какой это день: 1 – пн, 2 – вт, … , 7 – вс.
    // Используйте объект. Выведите все нечетные дни (номер и название) и их количество.
    // const day_number = prompt('Введите номер дня: ');
    // var amount =0 ; //////////////////////////////////////////////////////////////////////////////////////
    // let Week = {
    //     "1": "Понедельник",
    //     "2": "Вторник",
    //     "3": "Среда",
    //     "4": "Четверг",
    //     "5": "Пятница",
    //     "6": "Суббота",
    //     "7": "Воскресенье"
    //   };
    //   alert(`Номер дня ${day_number}: ${Week[day_number]}`)
     
    //   console.log('Нечетные дни: ');
    //   for (let key in Week) {
    //       if( +key%2 == 1){
    //         console.log(key+': '+ Week[key]);
    //         amount = amount+1;
    //       }  
    //   }
    //   console.log('Количество нечетных дней: '+ amount); 
    // 3.	На сайте все элементы оформлены одинаково. У всех кнопок одинаковые ширина, высота, цвет фона и текста. 
    // Все ссылки имеют одинаковые размер шрифта, гарнитуру и цвет текста. Для привлечения внимания элементы выделяют желтым цветом (цвет фона).
    //  Создайте объекты для кнопок, для ссылок и акцентных элементов (3 объекта!!). Используя эти объекты, создайте акцентные кнопки и ссылки.

    let text={
      color:"blue",
      size:"30px",
      Font: "Georgia, 'Times New Roman', Times, serif",
     
    }


    let button ={
       width : "40px",
      height:"25px",
      background: "pink"  
      
    };

    let links ={
      color:"purple",
    };

    let back ={
      shadow: "10px"
     
    };
    
    backgroundColor ={
      background: "yellow"
    }


    Object.assign(button, text);
    Object.assign(links, text);
    Object.assign(back, backgroundColor);



    document.getElementById("inform").style.color = links.color;
    document.getElementById("inform").style.fontSize = links.size;
    document.getElementById("inform").style.fontFamily = links.Font;

    document.getElementById("bt").style.width = button.width;
    document.getElementById("bt").style.height = button.height;
    document.getElementById("bt").style.background= button.background;
    document.getElementById("bt").style.color= button.color;

    document.getElementById("page").style.backgroundColor= back.background;


    // 4.	Имеется список товаров. Пользователь может добавить/удалить товар из списка,
    //  проверить наличие товара. Определите количество имеющего товара. Используйте коллекцию Set.  
//     let products= new Set(["апельсин", "яблоко", "банан"]);
//     let choise=1;
//     while(+choise !=0){

//         choise =  prompt(`1.Вывод товаров:\n2.Добавить товар\n3.Удалить товар\n4.Количество товара\n5.Есть ли товар в наличии\n0.выйти`);
   
//        switch (+choise) {
//             case 1:
//              console.log('Ваши товары: '); 
//              for (let product of products) 
//              console.log(product);
//              break;
//             case 2:
//                 const productNew = prompt('Введите товар, который надо добавить: ');
//                 products.add(productNew);
//             break;
//             case 3:
//                 const productDel = prompt('Введите товар, который надо добавить: ');
//                 products.delete(productDel);
//             break;
//             case 4:
//                 console.log('Количество товаров: ' + products.size); 
//             break;
//             case 5:
//                 const productHas = prompt('Введите товар, который надо проверить на наличие: ');
//                 if(products.has(productHas)==true){
//                     console.log('Продукт: ' + productHas + ' есть');
//                 } else{
//                     console.log('Продукта: ' + productHas + ' нет');
//                 }
//             break;
//             case 0:
//              break;
//            default:
//              alert( "Введено некорректное значение" );
//        }
//    }

//    5.	Используя коллекцию Map и ее методы, реализуйте корзину товаров. В корзине хранится информация о товаре: id, количество товара, цена.
//    Пользователь может добавить/удалить товар из корзины, изменить количество каждого товара. Рассчитайте количество позиций в корзине и сумму заказа.
// let Apple = { product_name: "apple", 
//              amount:10,
//              price:15
//     };
// let Tomato = { product_name: "tomatoes", 
//              amount:10,
//              price:15
//     }
// let basket = new Map([
//     [1, Apple],
//     [2, Tomato],
//     [1, Apple]
//   ]);
   
//   let choise=1;
//       while(+choise !=0){
  
//           choise =  prompt(`1.Вывод товаров:\n2.Добавить товар\n3.Удалить товар\n4.Изменить количество товара\n5.Количество позиций и сумма\n0.выйти`);
     
//          switch (+choise) {
//               case 1:
//                console.log('Ваши товары: '); 

//                basket.forEach((value, key, map) => {
//                 console.log('id: '+ key)

//                 for (let inf in value) {
//                   console.log(inf+': '+ value[inf]);
//                 }
//                });
//               break;
//               case 2:
//                 function makeBasket(name, number ,price) {
//                   return {
//                     product_name: name,
//                     amount: number,
//                     price: price
//                   };
//                 }
                
//                 let name1 = prompt('Введите название товара, который нужо добавить: ');
//                 let number = prompt('Введите количество товара, который нужо добавить: ');
//                 let price = prompt('Введите цену товара, который нужо добавить: ');
//                 let id = prompt('Введите id товара, который нужо добавить: ');
              
//                 let ProductAdd = makeBasket(name1, number ,price);
//                 basket.set(id, ProductAdd);
//               break;
//               case 3:
//                 let idDel = prompt('Введите id товара, который нужо удалить: ');
//               	basket.delete(+idDel);
//               break;
//               case 4:
//                 let idChange = prompt('Введите id товара, количество которого надо изменить: ');
//                 let amountNew = prompt('Введите количество: ');
//                 basket.get(+idChange).amount=amountNew;
//               break;
//               case 5:
//                 var sum = 0;
//                 console.log('Количество позиций: '+ basket.size);

//                 basket.forEach((value, map) => {
//                   sum+=+value.price;
//                 });
//                 console.log('Общая сумма: '+ sum);
//               break;
//               case 0:
//                break;
//              default:
//                alert( "Введено некорректное значение" );
//          }
//      }













 

  
 







//   for (let id of baskets.keys()) { 
    
//     //   for (let key in basket.values()) {

//     //         console.log(entry+' '+key+': '+ basket.values()[key]);

//     //       }
//     // alert(entry); // огурец,500 (и так далее)
//   }
  
