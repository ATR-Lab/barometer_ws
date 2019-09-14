import processing.serial.*;
Serial myPort;
String val;
PrintWriter output;

void setup()
{
   String portName = Serial.list()[0];
   myPort = new Serial(this, portName, 9600);
   output = createWriter( "data.txt" );
}

void draw()
{
   if ( myPort.available() > 0)
   {
     val = myPort.readStringUntil('\n');
     if (val != null) {
        output.println( val ); 
     }
   }
   println(val);
   
   
}

void keyPressed() {
    output.flush();  // Writes the remaining data to the file
    output.close();  // Finishes the file
    exit();  // Stops the program
}
