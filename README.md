# arduno_esc_control

Control and Programming of a HobbyWing Skywalker ESC
Makes programming without TX/RX easy... 


Commands: "r" attaches the servo pin to allow esc startup, sets throttle to lowest posit, run first or after detach.
          "t" sets full throttle (2000)
          "b" sets lowest thottle (1000)
          "d" detaches servo pin to prevent esc startup
           
 The default pin is set to pin 9.
           
  Arduio pin can be changed at firstESC.attach(9); //Remember it must be a PWM pin to work.
  
  Programming Use:
  
  type "r" to put the throttle at full (2000) and then power on your esc.
  type "t" or "b" according to the docs for your ESC.
  
  peace unmanaged.
  
          
         
