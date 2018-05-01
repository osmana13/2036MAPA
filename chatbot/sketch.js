var talk = new p5.Speech(); // computer to talk
var listen = new p5.SpeechRec(); // computer to listen and translate

var bot; //variable to hold the chatbot

var a,b,q;

function setup(){
  createCanvas(600,600);
  background(0);
    
    b = select('#submit');
    q = select('#user');
    a = select('#response');
    
    b.mousePressed(chatBot); // when button pressed run the chatbox function

    
    
    //brain stuff
    bot = new RiveScript();
    bot.loadFile("./brain.rive",botReady,botError); //2 functions
    
    //speech stuff
    talk.speak("hello you are talking to rivescripts");
    
    
listen.continuous = true; //constant listen
listen.onResult = showResult;  // trigger the function on every listen
listen.start(); //start listening
    
}
    

    function botReady() {
        
     bot.sortReplies();
        
    }
        
    
    function botError(){
        
    }
    
    
    
    function chatBot(){
        var question = q.value(); // get what is written in that 
        var reply = bot.reply("local-user",question);
        
        a.value(reply); // write out the answer
        talk.speak(reply); // talk the answer
        
    }
    




function draw (){
  fill( random(255), random(255), random(255),random(255));
  ellipse(mouseX,mouseY,50,50);
}

function showResult(){
  console.log(listen.resultString);
    q.value(listen.resultString);
    chatBot();
    

}



function keyPressed(){
}

