import gab.opencv.*;
import processing.video.*;
import java.awt.*;
import processing.serial.*;

Serial myPort;



Capture video;
OpenCV opencv;

void setup() {
  size(640, 480);
  video = new Capture(this, 640/2, 480/2);
  opencv = new OpenCV(this, 640/2, 480/2);
  opencv.loadCascade(OpenCV.CASCADE_FRONTALFACE);  

  video.start();


  myPort = new Serial(this, Serial.list()[3], 9600);
}

void draw() {
  scale(2);
  opencv.loadImage(video);

  image(video, 0, 0 );

  noFill();
  stroke(0, 255, 0);
  strokeWeight(3);
  Rectangle[] faces = opencv.detect();
  println(faces.length);

  if (faces.length >0) {
    for (int i = 0; i < faces.length; i++) {
      println(faces[i].x + "," + faces[i].y);
      //rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);
      myPort.write('0');
    }
  }
  
}

void captureEvent(Capture c) {
  c.read();
}


void keyPressed() {
  // Saves each frame as line-000001.png, line-000002.png, etc.
  saveFrame("line-######.png");
  myPort.write('0');
}