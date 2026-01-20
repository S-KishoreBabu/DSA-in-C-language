
let image = "";
fetch("https://dog.ceo/api/breeds/image/random") // Reader stream
    .then((data)=> data.json())  // promise object
    .then((res)=> image = res.message) // result object
    .catch((err)=> console.log(err.message));


document.querySelector("#btn")
    .addEventListener("click",()=> document.querySelector("#dogs").src = image);

async function generateImage(){
    let readerStream = await fetch("https://yesno.wtf/api");
    let result = await readerStream.json();
    let comedyContent = document.createElement("div");
    let gif = document.createElement("img");
    let message = document.createElement("h1");
    message.innerText = result.answer;
    gif.setAttribute("src",result.image);
    document.body.appendChild(gif);
    document.body.appendChild(message);
}

document.querySelector("#comedy").addEventListener("click",generateImage);