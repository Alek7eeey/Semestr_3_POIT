// 1. Реализуйте функцию без параметров. Вызовите ее с произвольным количеством аргументов.
// Если вы передали не более 3-х аргументов, то функция должна возвращать строку,
// состоящую из значений всех аргументов. Если вы передали более 3-х, но не более 5-ти
// аргументов – то типы аргументов. Если более 5-ти и не более 7-ми – то количество аргументов.
// Если более 7-ми – то сообщение о том, что количество аргументов очень большое. 

// console.log(func(1, 2, 3));
// console.log(func(1, '2', 3, 4, 5));
// console.log(func(1, '2', 3, 4, 5, 6, 7));
// console.log(func(1, '2', 3, 4, 5, 6, 7, 8, 9, 10));

// function func(...args) {
//     if (args.length <= 3) {
//         return args.join(', ');
//     }
//     else if (args.length <= 5) {
//         return args.map((item) => typeof item).join(', ');
//     }
//     else if (args.length <= 7) {
//         return args.length;
//     }
//     else {
//         return 'Количество аргументов очень большое';
//     }
// }

//-----------------------------------------------------------------------------

//ex2

//  window.a;
// alert(a);

// alert(a);
// window.a = 2;

// alert(a);
// window.a = 2;
// let a;

// alert(a);
// window.a = 2;
// var a;

// alert(a);
// let a = 2;

// let a = 2;
// window.a = 3;
// alert(a);

// var a = 2;
// window.a = 3;
// alert(a);
 
//-----------------------------------------------------------------------------

//ex 3

//  let s = 5;
// function sum()
// {
// alert(s);
// }

// sum(); 

//-----------------------------------------------------------------------------

// 4. Что выведет alert в примерах? Поясните почему так?
// На что ссылается [[Environment]] функций? Что будет содержать
// LexicalEnvironment при запуске функций? Что хранится в counter? Когда будет вызвана функция (*)?
// Вариант 1.

// function makeCounter() {
// let currentCount = 1;

// return function() {
// return currentCount++;
// }
// }

// let counter = makeCounter();
// alert( counter() ); //1
// alert( counter() ); //2
// alert( counter() ); //3

// let counter2 = makeCounter();
// alert( counter2() ); //1

//Вариант 2
// let currentCount = 1;

// function makeCounter() {
// return function() {
// return currentCount++;
// };
// }

// let counter = makeCounter();
// let counter2 = makeCounter();

// alert( counter() ); //1
// alert( counter() ); //2

// alert( counter2() ); //3
// alert( counter2() ); //4

//-----------------------------------------------------------------------------

//5. Выведите имена всех функций из предыдущих задач.
// function makeCounter() {
//     let currentCount = 1;
//     return function () {
//         return currentCount++;
//     };
// }
// let currentCount = 1;
// function makeCounter1() {
//     return function () {
//         return currentCount++;
//     };
// }
// alert(`
// Name of first func is ${makeCounter.name}
// Name of second func is ${makeCounter1.name}
// `);

//-----------------------------------------------------------------------------

// 6. Реализуйте каррированную функцию, которая рассчитывает объем прямоугольного параллелепипеда.
// Выполните преобразование функции для неоднократного расчёта объема прямоугольных параллелепипедов,
// у которых одно ребро одинаковой длины.

// function lenght_volume(l) {
// return (w, h) => {
// return l * w * h
// }
// }
// function volume(l) {
// return (w) => {
// return (h) => {
// return l * w * h
// }
// }
// }
// console.log('Объем1: '+ volume(1)(2)(3));

// console.log('Объем2: '+ lenght_volume(1)(2,3));
// console.log('Объем3: '+ lenght_volume(1)(2,5));
// const mul1 = lenght_volume(1);
// const mul2 = mul1(2, 3);
// const mul3 = mul1(4,6);
// console.log('Объем4: '+ mul2);
// console.log('Объем5: '+ mul3); 

//-----------------------------------------------------------------------------

// 7. Пользователь управляет движением объекта, вводя в модальное окно команды left, right, up, down.
// Объект совершает 10 шагов в заданном направлении (т.е. высчитываются и выводятся в консоль соответствующие координаты)
// и запрашивает новую команду.
// Разработайте генератор, который возвращает координаты объекта, согласно заданному направлению движения.

function* move() {
    var _a;
    let x = 0;
    let y = 0;

    for (let i = 0; i < 10; i++) 
    {
   _a = prompt("Enter direction");
    
    switch (_a.toLowerCase()) 
    {
    case "left":
    x--;
    break;
    case "right":
    x++;
    break;
    case "up":
    y++;
    break;
    case "down":
    y--;
    break;
    }
    yield [x, y];
    }

    }
    
    let generator = move();
    
    for (let i = 0; i < 10; i++) {
    alert(generator.next().value);
    }