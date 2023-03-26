const prompt = require("prompt-sync")();

console.log("---------------");
console.log("Front end class");
console.log("---------------");

console.log("Login");
let usuario = prompt("Usuário: ");
let senha = Number(prompt("Senha: "));

if (usuario === "Caio" || (usuario === "caio" && senha === 111)) {
console.log("Logado com sucesso");
} else {
console.log("Login incorreto");
}

console.log(" a - slides");
console.log(" c - codigos");
let opcao = prompt("Selecione a opção desejada: ");

switch (opcao) {
case "a": {
console.log("\tClick here: Aula 01");
console.log("\tClick here: Aula 02");
break;
}
}
