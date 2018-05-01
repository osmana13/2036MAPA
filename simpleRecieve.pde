import processing.serial.*;
Serial myPort;

float inValue = 0;

void setup () {
  size(400, 300);
  background(0);
  
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[3], 9600);
  
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
}

void draw () {
  background(0);
  fill(255, inValue, 0);
  ellipse(width/2, height/2, inValue, inValue);
}




void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');
println(inString);
  if (inString != null) {
    // trim off any whitespace:
    inString = trim(inString);

    inValue = float(inString);
    println(inValue);

    inValue = map(inValue, 0, 1023, 0, height);
  }
}