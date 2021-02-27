// Fig. 12.5: coverviewer.js 
// 201524582 정희석 coverviewer에서 'id' 수정하기
// Script to demonstrate dynamic styles used for animation. 
var interval = null; // keeps track of the interval
var speed = 6; // determines the speed of the animation
var count = 0; // size of the image during the animation
var name;
// called repeatedly to animate the book cover
function run()
{
   count += speed;

   // stop the animation when the image is large enough
   if ( count >= 375 ) 
   {
      window.clearInterval( interval );
      interval = null;
    } // end if
   var imgdisp = document.getElementById("mainimg");
    imgdisp.innerHTML = "<img style = \"width: " + (0.7656 * count + "px; ") + "height: " +
        (count + "px; \"") + "src =\"fullsize/" + name + "\"alt =\"Large version of\"" + name + ">";

} // end function run

// inserts the proper image into the main image area and
// begins the animation
function display( imgfile )
{
    if (imgfile != name || name == "0")
        return;
   if ( interval )
      return;
    var imgdisp = document.getElementById("mainimg");
    imgdisp.innerHTML = "<img style = \"width: 0px; height: 0px;\" src=\"fullsize/" +
        imgfile + "\"alt =\"Large version of\"" + imgfile + ">";
   count = 0; // start the image at size 0
   interval = window.setInterval( "run()", 10 ); // animate
} // end function display

// register event handlers
function start()
{
    document.addEventListener("click", Click, false);
} // end function start

function Click(e) {
    // put the original image back when the mouse moves away
    if (e.target.tagName.toLowerCase() == "img") {
        name = e.target.getAttribute("src");
        checkName();
        display(name);
        //document.getElementById("check").innerHTML = "<p>" + name + "</p>"
    } // end if
} // end function mouseOut

function checkName() {
    if (name == "thumbs/jhtp.jpg") {
        name = "jhtp.jpg";
    }
    else if (name == "thumbs/iw3htp.jpg") {
        name = "iw3htp.jpg";
    }
    else if (name == "thumbs/cpphtp.jpg") {
        name = "cpphtp.jpg";
    }
    else if (name == "thumbs/jhtplov.jpg") {
        name = "jhtplov.jpg";
    }
    else if (name == "thumbs/cpphtplov.jpg") {
        name = "cpphtplov.jpg";
    }
    else if (name == "thumbs/vcsharphtp.jpg") {
        name = "vcsharphtp.jpg";
    }
    else {
        name = "0";
    }
}


window.addEventListener( "load", start, false );

/*************************************************************************
* (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
* Pearson Education, Inc. All Rights Reserved.                           *
*                                                                        *
* DISCLAIMER: The authors and publisher of this book have used their     *
* best efforts in preparing the book. These efforts include the          *
* development, research, and testing of the theories and programs        *
* to determine their effectiveness. The authors and publisher make       *
* no warranty of any kind, expressed or implied, with regard to these    *
* programs or to the documentation contained in these books. The authors *
* and publisher shall not be liable in any event for incidental or       *
* consequential damages in connection with, or arising out of, the       *
* furnishing, performance, or use of these programs.                     *
*************************************************************************/