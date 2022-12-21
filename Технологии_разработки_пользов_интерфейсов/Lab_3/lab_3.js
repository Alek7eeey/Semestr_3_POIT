let num = 1;
while(num == 1)
{
    let choice = prompt(`Выберите задание: `);
    
    switch(choice)
    {
        case '1':
            {
                let str = prompt(`Введите комментарий`);
                let n = 100;
                Ex1(str,n);
                break;
            }

        case '2':
            {
                let WeekDay = prompt(`Введите числовое значение в пределах от 1 до 7`);
                Ex2(WeekDay);
                break;
            }
            
        case '3':
        {
                Ex3();
                break;
        }

        case '4':
        {
                Ex4();
                break;
        }

        case '5':
        {
                Ex5();
                break;
        }
    }
}

function Ex1(comment, size)
{
    if(comment.length < size)
    {
        var stroke = comment.split(' ');
       
        for (let i=0; i<stroke.length; i++) 
        { 

            if(stroke[i].indexOf('кот')!=-1 || stroke[i].indexOf('Кот')!=-1)
            {
                stroke[i]= '*' ;
            }
                
            if(stroke[i].indexOf('Собак')!=-1||stroke[i].indexOf('собак')!=-1)
            {
                    stroke[i] = stroke[i].toUpperCase();
            }
                
            if(stroke[i]=="пес")
            {
                stroke[i]="многоуважаемый пес";
            }
        } 
        alert(stroke.join(' ')); //метод join() объединяет все элементы массива (или массивоподобного объекта) в строку.
    }

    else 
    {
        alert(`Длина комментария больше допустимого!`);
    }
}

function Ex2(day)
{
    let map = new Map();
    map.set('1', "понедельник");    
    map.set('2', "вторник");      
    map.set('3', "среда"); 
    map.set('4', "четверг");      
    map.set('5', "пятница"); 
    map.set('6', "суббота");      
    map.set('7', "воскресенье"); 

    let array = "Дни недели, которые соответствуют нечётным числам: ";
    let count = 0;
    
for (let i = 1; i <= 7; i++)
{
    if(i % 2 != 0)
    {
        let num = String(i);
        array += map.get(num);
        array += ', ';
        count ++;
    }
}
    array += "\n\nКоличество нечётных дней: " + count + "\n\nЧислу " + day + " соответствует: " + map.get(day);
    alert(array);
}

function Ex3()
{
    let text = {
      color: "blue",
      size: "30px",
      Font: "Georgia, 'Times New Roman', Times, serif",
    };

    let back ={
        shadow: "10px"
      };

    let button = {
       width : "40px",
       height:"25px",
       background: "pink"  
     };
 
     let links = {
       color:"purple",
     };

     let backgroundColor = {
        background: "yellow"
      };
  
      let newobj = Object.assign({}, button, text);
      let newobj2 = Object.assign({}, links, text);
      let newobj3 = Object.assign({}, back, backgroundColor);

      alert(`Объект 1 (кнопка + текст):
ширина кнопки: ${button.width}\nвысота кнопки: ${button.height}\nфоновый цвет: ${button.background}`+
`\nцвет: ${text.color}\nшрифт: ${text.Font}\nразмер текста: ${text.size}`);

      alert(`Объект 2 (ссылка + текст):
цвет: ${text.color}\nшрифт: ${text.Font}\nразмер текста: ${text.size}`);

      alert(`Объект 3 (акцентный элемент + фоновый цвет):
тень: ${back.shadow}\nфоновый цвет: ${backgroundColor.background}`);
      
}

function Ex4()
{
    var products = new Set(["Линейка", "Апельсин", "Тетрадь"]);

    let choiceEx4 = 1;
    while(choiceEx4 != 0)
    {
        choiceEx4 = prompt(`1 - добавить элемент в список\n2 - удалить элемент из списка\n3 - проверить наличие товара`+
        `\n4 - количество товаров в списке\n5 - вывод всего списка\n6 - выход`);

        switch(choiceEx4)
        {
            case '1':
                {
                    const productNew = prompt('Введите товар, который надо добавить: ');
                    products.add(productNew);
                    alert(`Товар добален!`);
                    break;
                }

            case '2':
                {
                    const productDel = prompt('Введите товар, который надо добавить: ');
                    products.delete(productDel);
                    alert(`Товар удалён!`);
                    break;
                }
            case '3':
                {
                    const productHas = prompt('Введите товар, который надо проверить на наличие: ');
                        
                    if(products.has(productHas) == true)
                    {
                       alert(`Продукт ${productHas} есть!`);
                    } 
                        
                    else
                    {
                        alert(`Продукт ${productHas} отсутствует!`);
                    }
                    break;
                }

            case '4':
                {
                    alert('Количество товаров: ' + products.size);
                    break;
                }
                
            case '5':
                {
                    let arrEx4 = '';
                    for (let product of products) 
                    {
                     arrEx4 += product + ' ';
                    }
                    
                    alert(`Ваши товары:\n` + arrEx4);
                    break;
                }
            case '6':
                {
                    choiceEx4 = 0;
                    alert(`Выход к выбору задания!`);
                    break;
                }    
        }
    }
}

function Ex5()
{
    let Book = 
    { 
              product_name: "book", 
              amount:25,
              price:15
     };

    let Pencil = 
    {         product_name: "pencil", 
              amount:55,
              price:5
     };

     let Orange = 
     {         product_name: "orange", 
               amount:35,
               price:10
      };

    let basket = new Map([
     [1, Book],
     [2, Pencil],
     [3, Orange]
   ]);

    function addProduct(name, count, price)
    {
        return {
            product_name: name, 
            amount: count,
            price: price
        };
    }

   let choiceEx5 = 1;

   while(choiceEx5 != 0)
   {
    choiceEx5 =  prompt(`1.Вывод товаров:\n2.Добавить товар\n3.Удалить товар\n4.Изменить количество товара\n5.Количество товаров и сумма заказа\n6.выйти`);
    
    switch(choiceEx5)
    {
       case '1':
        {
            let arrEx5 = '';
            basket.forEach((value, key, map) => 
            {
                arrEx5 = arrEx5 + '\nid: '+ key + '\n';
                for (let inf in value) 
                {
                    arrEx5 = arrEx5 + inf + ': ' + value[inf] + '\n';
                }
            });

            alert(`Ваши товары:\n` + arrEx5);
            break;
        } 

        case '2':
            {
                let name1 = prompt('Введите название товара, который необходимо добавить: ');
                let count = prompt('Введите количество товара который нужно добавить: ');
                let mark = prompt('Введите цену товара, который нужно добавить: ');
                let idnew = prompt('Введите id товара, который нужно добавить: ');
                
                var a = basket.forEach((value, key, map) => {
                    while(key==+idnew)
                    {
                      alert(`Данный ID уже занят!`);
                      idnew = prompt('Введите id товара, который нужо добавить: ');
                      a;        
                }
                  });

                let ProductAdd = addProduct(name1, count, mark);
                basket.set(idnew, ProductAdd);

                alert(`Товар добавлен!`);
                break;
            }

        case '3':
        {
            let IDdelet = prompt(`Введите ID товара, который необходимо удалить`);
            basket.delete(IDdelet);
            break;
        }

        case '4':
        {
            let idChange = prompt(`Введите ID товара, количество которого, вы собираетесь изменить`);
            let newCount = prompt(`Введите новое количество данного товара`);
            basket.get(+idChange).amount = +newCount;
            break;
        }

        case '5':
        {
            let sumOfProduct = 0;
            basket.forEach((value, map) => 
            {
            sumOfProduct += value.price;
            });

            alert(`Количество товаров: ${basket.size}\n`+`Сумма всх товаров: ${sumOfProduct}`);
            break;
        }

        case '6':
            {
                choiceEx5 = 0;
                alert(`Выход к выбору задания!`)
                break;
            }
    }
   }
}