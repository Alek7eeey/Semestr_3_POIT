let buttonAdd = document.querySelector(".Add");
let buttonRemove = document.querySelector(".Remove");
let buttonChangeBack = document.querySelector(".ChangeBack");
let buttonAddReady = document.querySelector(".AddReady");
let price = 1500;

let products = new Map();

try {
    buttonAdd.onclick = () => {
        let name = prompt("Введите название товара:");
        if (name == null) {
            throw new Error("Вы не ввели название товара!");
        }
        let price = Number(prompt("Введите цену товара:"));
        if (price == null ||
            isFinite(price) == false) {
            throw new Error("Некорректная цена товара!");
        }
        let pathToImg = prompt("Введите путь к изображению товара:");
        if (pathToImg == null) {
            throw new Error("Вы не ввели путь к изображению товара!");
        }

        let product = new Product(name, price, pathToImg);
        product.Wrapper = document.querySelector(".products");
        products.set(product.ID, product);
        product.toHTML();
    };

    buttonRemove.onclick = () => {
        let answer;
        answer = prompt("Введите название товара или айди:")
        if (answer == null) {
            answer = "default";
        }
        if (answer == "default") {
            throw new Error("Вы не ввели название товара или айди!");
        }
        let product = products.get(Number(answer));
        if (product == undefined) {
            product = Array.from(products.values())
            find(product => product.Name === answer);
        }
        product.Remove();
    };

    buttonChangeBack.onclick = () => {
        let prods = Array.from(document.querySelectorAll(".product"));
        for (let i = 0; i < prods.length; i++) {
            if ((i + 1) % 2 != 0) {
                prods[i].style.backgroundColor = "RGBA(233,233,233,0.6)";
            }
        }
    };

    buttonAddReady.onclick = () => {
        let name = "KAD";
        price = price + 100;
        let pathToImg = "D://studing//3 семестр//Технологии_разработки_пользов_интерфейсов//Lab_6(n)//image//computer.jpg";
        let product = new Product(name, price, pathToImg);
        product.Name += " " + product.ID;
        product.Wrapper = document.querySelector(".products");
        products.set(product.ID, product);
        product.toHTML();
    };
} catch (error) {
    alert(error.message);
}