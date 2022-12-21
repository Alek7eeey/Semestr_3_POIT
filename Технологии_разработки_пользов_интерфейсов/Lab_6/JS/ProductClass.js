let idMaker = 1;

class Product {
    wrapper = document.querySelector(".products");
    id;
    name;
    price;
    pathToImg;
    isInABasket = false;
    htmlElement;
    get ID() {
        return this.id;
    }
    get Wrapper() {
        return this.wrapper;
    }
    set Wrapper(value) {
        this.wrapper = value;
    }
    get Name() {
        return this.name;
    }
    set Name(value) {
        this.name = value;
    }
    get Price() {
        return this.price;
    }
    set Price(value) {
        this.price = value;
    }
    get PathToImg() {
        return this.pathToImg;
    }
    set PathToImg(value) {
        this.pathToImg = value;
    }
    get IsInABasket() {
        return this.isInABasket;
    }
    set IsInABasket(value) {
        this.isInABasket = value;
    }
    constructor(name, price, pathToImg) {
        this.id = idMaker++;
        this.Name = name;
        this.Price = price;
        this.PathToImg = pathToImg;
        this.Wrapper = document.querySelector(".products");
    }

    ToString() {
        return `
            <img class="product-img" src="${this.pathToImg}" alt="${this.Name}">
            <div class="product-name">${this.Name}</div>
            <div class="product-price">BYN ${this.price}</div>
            ${this.IsInABasket = (new ButtonClass("product-btn-to product-btn", "В корзину")).toHTML()}
        `;
    }

    toHTML() {
        let product = document.createElement("div");
        product.classList.add("product");
        product.id = this.id.toString();
        product.innerHTML = this.ToString();
        this.Wrapper.innerHTML += product.outerHTML;
        this.htmlElement = product;
        buttonsAddToBasket = document.querySelectorAll(".product-btn");
    }

    Remove() {
        this.Wrapper.removeChild(document.getElementById(this.id.toString()));
    }
}