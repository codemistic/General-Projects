var canvas = document.getElementById("canvas");
        var ctx = canvas.getContext('2d');
        var rightPressed,leftPressed;

        var score,ball,paddle;
        var requestID;
        var gameSTATE = false;
        var gameOVER = false;

        var bricks;
        var r = 15,c = 11;
        var lb = 20,wb = 60;

        function reset()
        {
          score = 0;gameOVER = false;gameSTATE = 0;
          r=15;c=11;lb=20;wb=60;
          bricks = new Array;

        ball = {
            px:canvas.width/2,
            py:canvas.height-25,
            vx:6,vy:-6,
            rad:8,
            draw:function()
            {
               ctx.fillStyle  = "white";
               ctx.beginPath();
               ctx.arc(this.px,this.py,this.rad,0,Math.PI*2,true);
               ctx.fill();  
            }
            
        };

        paddle = {
            wid:100,ht:10,
            posX:(canvas.width-100)/2,
            posY:canvas.height-15,

            drawPaddle:function()
            {
                ctx.fillStyle = "white";
                ctx.fillRect(this.posX,this.posY,this.wid,this.ht);
            }

        };
         
        function Brick(x,y,r,g,b)
        {
          this.xc = x;
          this.yc = y;
          this.displayBrick = function()
          {
            ctx.fillStyle = 'rgb(' + r + ',' + g + ',' + b + ')';
            ctx.strokeStyle = 'black';
            ctx.fillRect(this.xc,this.yc,wb,lb);
          }

        } 
       
       for(let i=1;i<2;i++)
       {
         for(let j=1;j<c;j++)
         {
           bricks.push(new Brick(65*j-60,25*i-20,rand(),rand(),rand()));
         }
       }

       for(let i=2;i<6;i++)
       {
         for(j=1;j<3;j++)
         {
          if(Math.random()*10<8)
          bricks.push(new Brick(65*j-60,25*i-20,rand(),rand(),rand()));
         }
         for(j=6;j<c;j++)
         {
          if(Math.random()*10<8)
          bricks.push(new Brick(65*j-60,25*i-20,rand(),rand(),rand()));
         }

       }

       for(let i=6;i<14;i++)
       {
         for(let j=1;j<6;j++)
         {
           if(Math.random()*10<7)
            bricks.push(new Brick(65*j-60,25*i-20,rand(),rand(),rand()));
         }
         for(let j=8;j<c;j++)
         {
          if(Math.random()*10<7)
            bricks.push(new Brick(65*j-60,25*i-20,rand(),rand(),rand()));
         }
       }
       for(let i=14;i<16;i++)
       {
        for(let j=1;j<6;j++)
         {
           if(Math.random()*10<5)
            bricks.push(new Brick(65*j-60,25*i-20,rand(),rand(),rand()));
         }
         for(let j=8;j<c;j++)
         {
           if(Math.random()*10<5)
            bricks.push(new Brick(65*j-60,25*i-20,rand(),rand(),rand()));
         }
       }
       ctx.font = "30px serif";
       ctx.fillStyle = 'white';
       ctx.fillText("Tap to play!", 270, 550);
       ball.draw();
       paddle.drawPaddle();
       for(let i = 0;i<bricks.length;i++)
       {
         bricks[i].displayBrick();     
       }

      }

      reset();

        document.addEventListener("keydown", keyDownHandler, false);
        document.addEventListener("keyup", keyUpHandler, false);

        function keyDownHandler(e) 
        {
          if(e.key == "Right" || e.key == "ArrowRight")
           {
             rightPressed = true;
           }
           else if(e.key == "Left" || e.key == "ArrowLeft") 
           {
             leftPressed = true;
           }
        }

        function keyUpHandler(e) 
        {
           if(e.key == "Right" || e.key == "ArrowRight") {
            rightPressed = false;
           }
           else if(e.key == "Left" || e.key == "ArrowLeft") {
            leftPressed = false;
           }
        }
        

       function rand()
       {
         var color = Math.floor(Math.random()*6 +3)*32 -1;
         return  color;
       }

       function collisionDetected()
       {
         for(var x=0;x<bricks.length;x++)
         {
           if(ball.px<bricks[x].xc+wb+ball.rad && ball.px>bricks[x].xc-ball.rad && ball.py>bricks[x].yc-ball.rad &&
              ball.py<bricks[x].yc+lb+ball.rad)
           {
             if(ball.py<(bricks[x].yc+lb+1) && ball.py>(bricks[x].yc-2))
             {
               ball.vx *= -1;
               bricks.splice(x,1);
               score++;
             }
             else if(ball.px<(bricks[x].xc+wb+1) && ball.px>(bricks[x].xc-2))
             {
               ball.vy *= -1;
               bricks.splice(x,1);
               score++;
             }
           }   
         } 
       }

       function gameOver()
       {
         ctx.font = "70px monaco";
         ctx.fillStyle = 'white';
         ctx.fillText("GAME OVER",130,200);
         ctx.font = "30px monaco";
         ctx.fillText("Your score:"+score,250,300);
         ctx.fillText("Made with love by Mallick",180,350);
         ctx.fillText("Tap to play again",230,400);
         gameSTATE = false;
         gameOVER = true; 
       }
       function userwon()
       {
         ctx.font = "60px Georgia";
         ctx.fillStyle = 'yellow';
         ctx.fillText("YOU WON!",200,250);
         gameSTATE = false;
         gameOVER = true;
       }

        function theGame()
        {
          ctx.clearRect(0,0,canvas.width,canvas.height);

         if(gameSTATE){ 
          ball.draw();
          paddle.drawPaddle();
          collisionDetected();

          if(ball.vy>0 && ball.py>canvas.height-15-ball.rad && ball.py<canvas.height)
          {
            if(paddle.posX<ball.px && ball.px<(paddle.posX+paddle.wid))
            {ball.vy *= -1;}
           
          }
         
          for(let i = 0;i<bricks.length;i++)
          {
             bricks[i].displayBrick();     
          }
                                 
          ball.px += ball.vx;
          ball.py += ball.vy;

          if(ball.px>=canvas.width-ball.rad||ball.px<=ball.rad)
            ball.vx *= -1;
          if(ball.py<=ball.rad)
            ball.vy *= -1;
           
          if(rightPressed && paddle.posX < canvas.width-paddle.wid-5) {
            paddle.posX += 10;
           }
          else if(leftPressed && paddle.posX-10 > 0) {
            paddle.posX -= 10;
          }
           
          ctx.font = "15px serif"; 
          ctx.fillStyle = 'red';
          ctx.fillText("SCORE:"+score,20,690);
        }

          if(ball.py>canvas.height+15){ gameOver();}
          if(bricks.length == 0){userwon();}

          window.requestAnimationFrame(theGame);
           
        }

       canvas.addEventListener("click",function(e)
       {
         if(!gameSTATE){  
           if(!gameOVER)
           {
             requestID =  window.requestAnimationFrame(theGame);
             gameSTATE = true;
          
           }
         } 
         if(gameOVER && !gameSTATE)
         {
           reset();
           gameSTATE = true; 
         } 
       });