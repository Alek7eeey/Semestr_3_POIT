class ButtonClass {
    className;
    text;
    get ClassName() {
        return this.className;
    }
    set ClassName(value) {
        this.className = value;
    }
    get Text() {
        return this.text;
    }
    set Text(value) {
        this.text = value;
    }
    constructor(className, text) {
        this.className = className;
        this.text = text;
    }

    toHTML() {
        return `<button class="${this.className}">${this.text}</button>`;
    }
}