//ex1
let Radius = prompt(`Введите радиус круга`);

// Function Declaration
function Square(Radius)
{
    return 3.1416 * (Radius * Radius);
}

//Function Expression
let lenghts = function(Radius)
{
    return 2*3.1416*Radius;
}

//Функция - стрелка
let Diametr = (Radius) => Radius*2;

alert(`Диаметр = ${Diametr(Radius)}\nДлина окружности = ${lenghts(Radius)}\nПлощадь круга = ${Square(Radius)}`)

//ex2
let Str3 = prompt(`Введите строку`);
Str2 = " строка: ";
let output = function (Str2, Str3,Str1 = "Ваша")
{
    alert(Str1+Str2+Str3);
} 
output(Str2, Str3);

//ex3
let nameOfStudent = prompt(`Введите имена присутствующих студентов через пробел`);

function Count_of_students(nameOfStudent)
{
    let correctWord = nameOfStudent.split(' ');
    alert(`Количество учащихся: ${correctWord.length}`);
}
Count_of_students(nameOfStudent);

//ex4
const amount_var=(26**5)*(10**3);
const time=amount_var*3;

const sec_in_year=60*60*24*365;
const sec_in_month=60*60*24*30;
const sec_in_day=60*60*24;

const year = Math.floor(time/sec_in_year);
const month = Math.floor((time-year*sec_in_year)/sec_in_month)
const day = Math.floor((time-year*sec_in_year-month*sec_in_month)/sec_in_day)
const hour = Math.floor((time-year*sec_in_year-month*sec_in_month-day*sec_in_day)/3600)
const min = Math.floor((time-year*sec_in_year-month*sec_in_month-day*sec_in_day -hour*3600)/60)
const sec = (time-year*sec_in_year-month*sec_in_month-day*sec_in_day -hour*3600-min*60)

alert(` ${year} лет ${month} месяцев ${day} дней ${hour} часов ${min} минут ${sec} секунд `);

//ex5
let information = prompt("Введите данные");

if (isFinite(Number(information)) && !information.includes(".")) {
    let number = Number(information);
    let hNumber = number.toString(16).toUpperCase();
    alert(`В 16-ой системе счисления: ${hNumber}`);
}
else if (isFinite(Number(information)) && information.includes(".")) {
    let number = Number(information);
    alert(`
        Округление до наибольшего: ${Math.ceil(number)}\n
        Округление до наименьшего: ${Math.floor(number)}\n
        Ближайшее целое: ${Math.round(number)}\n
    `);
}
else {
    alert(`
        Верхний регистр: ${information.toUpperCase()}\n
        Нижний регистр: ${information.toLowerCase()}\n
    `);
}

//ex6
let dictionary_word = prompt("Введите правильно словарное слово - 'в_р_бей' буквами нижнего регситра");
let correctWord="воробей";
let count_inEx6 = 0;

for(let i = 0; i<dictionary_word.length;i++)
{
 if(correctWord[i] == dictionary_word[i])  
 {
    count_inEx6++;
 } 

 else
 {
    alert(`${i+1}-ая буква ("${dictionary_word[i]}") в слове написана не правильно`);
 }
} 

if(count_inEx6 == dictionary_word.length)
{
   alert(`Вы ввели верное слово!`)
}

//ex7
let legOfTriangle_1 = prompt("Укажите длину первого катета:");
let legOfTriangle_2 = prompt("Укажите длину второго катета:");
let choiceInEx7;
let hypotenuse = Math.sqrt(Math.pow(legOfTriangle_1,2)+Math.pow(legOfTriangle_2, 2));

function calculate(legOfTriangle_1, legOfTriangle_2, hypotenuse)
{
let SquareInEx7 = (legOfTriangle_1*legOfTriangle_2)/2;

let P = +hypotenuse + +legOfTriangle_1 + +legOfTriangle_2;

let Height = (2 * SquareInEx7 / legOfTriangle_1);
let cos = legOfTriangle_1 / hypotenuse;
let sin = legOfTriangle_2 / hypotenuse;
let tg = legOfTriangle_2 / legOfTriangle_1;
let ctg = legOfTriangle_1 / legOfTriangle_2;

alert(`
       Первый катет: ${legOfTriangle_1} см\n
       Второй катет: ${legOfTriangle_2} см\n
       Гипотенуза: ${hypotenuse.toFixed(2)} см\n
       Площадь: ${SquareInEx7} см^2\n
       Периметр: ${+P.toFixed(2)} см \n
       Высота: ${Height.toFixed(2)} см\n
       Cos: ${cos.toFixed(2)} °\n
       Sin: ${sin.toFixed(2)} °\n
       Tg: ${tg.toFixed(2)} °\n
       Ctg: ${ctg.toFixed(2)} °`);
}

calculate(legOfTriangle_1, legOfTriangle_2, hypotenuse);