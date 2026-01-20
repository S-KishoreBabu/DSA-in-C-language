// go to school
// got to college
// go to job

// result .success or failure

function School(name,schoolName,callback){
    console.log(`${name} went to ${schoolName}`);
    let score = Math.floor(Math.random()*100)
    console.log(`he got ${score}`);
    let collegeName = "ABCD COLLEGE"
    if(score < 40){
        collegeName = "XYZ COLLGE";
    }
    else if(score >= 40 && score < 70){
        collegeName = "vit COLLEGE"
    }
    else{
        collegeName = "IIT DELHI"
    }
    callback(name,collegeName);
}

function College(name,collegeName,callback){
    console.log(`${name} went to ${collegeName}`);
    let score = Math.floor(Math.random()*100)
    console.log(`he got ${score}`);
    let jobProfile = "Intern"
    if(score < 40){
        jobProfile = "Intern";
    }
    else if(score >= 40 && score < 70){
        jobProfile = "Junior Developer"
    }
    else{
        jobProfile = "Software Engineer"
    }
    callback(name,jobProfile);
}

function Job(name,jobProfile){
    console.log(`${name} got the job profile of ${jobProfile} in codingMart`);
    let happinessScore = Math.floor(Math.random()*100)
    if(happinessScore < 40){
        console.log("He is not happy with his job");
    }
    else if(happinessScore >= 40 && happinessScore < 70){
        console.log("He is satisfied with his job");
    }
    else{
        console.log("He is very happy with his job");
    }
}

function sports(name,collegeName){
    console.log(`${name} is not willing go to ${collegeName} he love sports so he decided to sports`);
}

// School("barani","jai saradha school",(name,college)=>{
//     College(name,college,(name,job)=>{
//         Job(name,job);
//     })
// })

// School("barani","xyz school",(name,college)=>{
//     sports(name,college);
// })

function cookRice(){
    return new Promise((resolve,reject)=>{
        console.log("Rice cooking");
        setTimeout(()=>{
            resolve("Rice Cooked");
        },2000)
    })
}

function cookSambaar(){
    return new Promise((resolve,reject)=>{
        console.log("cooking Sambaar");
        setTimeout(()=>{
            resolve("sambaar Cooked");
        },2000);
    });
}

function serveFood(){
    return new Promise((resolve,reject)=>{
        console.log("serving Food");
        setTimeout(()=>{
            resolve("Food served");
        },2000);
    });
}

// cookRice()
//     .then((data)=>{
//         console.log(data);
//         return cookSambaar();
//     })
//     .then((data)=>{
//         console.log(data);
//         return serveFood();
//     })
//     .then((data)=>{
//         console.log(data);
//     })


async function preparefood(){
    try{
        console.log("food preparation started");
        let rice = await cookRice();
        console.log("->",rice);
        appendContent(rice);
        let sambaar = await cookSambaar(rice);
        console.log("->",sambaar);
        appendContent(sambaar);
        let service = await serveFood(sambaar);
        console.log("->",service);
        appendContent(service);
    }
    catch(e){
        console.log(e);
    }
}


function appendContent(data){
    let pic = document.createElement("div");
    pic.innerHTML = data;
    pic.classList.add("result");
    document.body.appendChild(pic);
}

// preparefood();



