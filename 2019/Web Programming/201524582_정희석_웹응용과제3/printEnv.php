<!DOCTYPE html>

<!-- 201524582 정희석 -->
<!-- Assignment 03 Print Environment -->
<html>
   <head>
      <meta charset = "utf-8">
      <title>Print Environment</title>  
      <style type = "text/css">
         p { margin: 0px; }
      </style>
   </head>
   <body>
      <p>This Data is Environment of Server and Client</p>
      <?php
         // iterate through array $_COOKIE and print
         // name and value of each cookie
         //foreach ($_COOKIE as $key => $value )
         //   print( "<p>$key: $value</p>" );
         print( "<p> 서버 환경) <br>");
         print_r($_SERVER);
         print("</p>" );
         print( "<p> 클라이언트 환경 ) <br>");
         print_r($_ENV);
         print("</p>" );
      ?><!-- end PHP script -->
   </body>
</html>

<!--
**************************************************************************
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
**************************************************************************
-->
