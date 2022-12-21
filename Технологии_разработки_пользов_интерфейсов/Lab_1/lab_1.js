//ex_1
function exponent(x, n) 
{
    let result = 1;

    for (var i = 0; i < n; i++)
        result *= x;

    return result;
}

let x = prompt("x?", '');
let n = prompt("n?", '');

if (n < 0) 
{
    alert(`Степень ${n} не поддерживается, введите целую степень, большую 0`);
} else {
    alert(exponent(x, n));
}

//ex_2
let user_name = "Aleksey";
let city = "Minsk";
let year_of_birth = 2003;
let color = "red";

let choice = prompt('Введите ДА или НЕТ');
alert(`Вы ввели ${choice}`);

let Inf = Infinity;
let num = 532;
let perimetr_rect = "120mm";
alert(`Введённые данные неверные!`)

//ex_3
let a = 5;
alert(typeof a);

let name = "Name";
alert(typeof name);

let i = 0;
alert(typeof i);

let double = 0.23;
alert(typeof double);

let result = 1 / 0;
alert(typeof result);

let answer = true;
alert(typeof answer);

let no = null;
alert(typeof no);

//ex_4
let side_1 = 45,
    side_2 = 21;
let S_rect = side_1 * side_2;
alert(`Площадь четырёхугольника = ${S_rect}`);

//ex_5
let S_sq_A = 5 * 5;
let S_rect_B = 45 * 21;
let result_2 = S_rect_B / S_sq_A;
alert(`Поместится ${result_2} квадратов A`);

//ex_6
let i_2 = 2;
let a_2 = i_2,
    b_2 = i_2;
alert(++a_2 > b_2++);

//ex_7
alert(`Привет` > `привет`); //false
alert(`Привет` > `Пока`); //true
alert(45 < 53); //true 
alert(false > 3); //false 
alert(true < 3); //true 
alert(3 == `5mm`); //всегда false 
alert(true < undefined); //false

//ex_8
alert(`Введённые данные неверные`);

//ex_9
var answer_2;
var qestion = prompt(`Ответ на секретный вопрос`, `Секретный ответ`);

//ex_10
var login = "9999";
var password = "parol";
var answ_login = prompt(`Введите логин`);
var answ_passw = prompt(`Введите пароль`);

if (answ_login == login && answ_passw == password) {
    alert(`Вход успешно выполнен!`)
} else
    alert(`Вход не выполнен!`);

//ex_11
let ex_1 = prompt(`Сдал ли студент экзамен по математике? (ДА - "+", НЕТ - "-")`);
let ex_2 = prompt(`Сдал ли студент экзамен по русскому? (ДА - "+", НЕТ - "-")`);
let ex_3 = prompt(`Сдал ли студент экзамен по английскому? (ДА - "+", НЕТ - "-")`);

if (ex_1 == '+' && ex_2 == '+' && ex_3 == '+') {
    alert(`Студент переведён на второй курс!`);
} else if (ex_1 == '-' && ex_2 == '-' && ex_3 == '-') {
    alert(`Студент отчислен!`);
} else if (ex_1 == '-' || ex_2 == '-' || ex_3 == '-') {
    alert(`Студента ожидает пересдача!`);
}

//ex_12
let num_a = prompt(`Введите число a:`);
let num_b = prompt(`Введите число b:`);
alert(`Cумма чисел = ${num_a+num_b}`);

//ex_13
let ex13_1 = true + true;
let ex13_2 = 0 + "5";
let ex13_3 = 5 + "mm";
let ex13_4 = 8 / Infinity;
let ex13_5 = 9 * "\n9";
let ex_13_6 = null - 1;
let ex13_7 = "5" - 2;
let ex13_8 = "5px" - 3;
let ex13_9 = true - 3;
let ex13_10 = 7 || 0;

//ex_14
let arr = [10];
for (let count = 0; count < 10; count++) {
    arr[count] = count + 1;

    if (arr[count] % 2 == 0)
        arr[count] += 2;

    if (arr[count] % 2 != 0)
        arr[count] = `${arr[count]}mm`;

    alert(`${arr[count]}`);
}

//ex_15
let choice_user;
while (true) {

    choice_user = prompt(`Введите число:`);

    if (choice_user == 100) {
        break;
    }
}

//ex_16
let week = ["понедельнику", "вторнику", "среде", "четвергу", "пятнице", "субботе", "воскресенью"];
let choice_week = prompt(`Введите число:`) - 1;
alert(`Данная цифра соответствует ${week[choice_week]}`);