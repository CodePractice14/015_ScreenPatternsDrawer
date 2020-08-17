<!DOCTYPE html>
<html>
   <head>
      <meta http-equiv="content-type" content="text/html; charset=utf-8" />
      <style>
         table {
         font-family: arial, sans-serif;
         border-collapse: collapse;
         width: 50%;
         }
         td, th {
         border: 1px solid #dddddd;
         text-align: left;
         padding: 2px;
         }
         tr:nth-child(even) {
         background-color: #dddddd;
         }
      </style>
      <header>
         <title>Screen Pattern Drawer</title>
      </header>
   </head>
   <body>
      <h2>Screen Pattern Drawer Control Panel</h2>
      <br><br><br>
      <form method="POST">
      <table>
         <tr>
            <th>Image</th>
            <th>Size of Elements</th>
            <th>Action</th>
         </tr>
         <tr>
            <td>Horizontal stripes</td>
            <td><input type="text" id="m_lineHeight" name="m_lineHeight"></td>
            <td><input type="submit" name="DrawHorizontalStripes" value ="Show!" /></td>
         </tr>
         <tr>
            <td>Vertical stripes</td>
            <td><input type="text" id="m_lineWidth" name="m_lineWidth"></td>
            <td><input type="submit" name="DrawVerticalStripes" value ="Show!" /></td>
         </tr>
         <tr>
            <td>Chessboard</td>
            <td><input type="text" id="m_squareSize" name="m_squareSize"></td>
            <td><input type="submit" name="DrawCheesStripes" value ="Show!" /></td>
         </tr>
      </table>
      </form>
   </body>

   <?php
      #if this page is called as a "POST" .. 
      if($_SERVER['REQUEST_METHOD'] == 'POST')
       {
          debug_to_console("function has been called as POST");
          
          if($_POST["m_lineHeight"] != "")
          {
            serverSend_DrawHorizontalStripes();
          }
          else if($_POST["m_lineWidth"] != "")
          {
            serverSend_DrawVerticalStripes();
          }
          else if($_POST["m_squareSize"] != "")
          {
            serverSend_DrawChessStripes();  
          }
      }

      function serverSend_DrawHorizontalStripes()
      {     
         $callerFunction = "HorizontalStripes";
         $callerValue = $_POST["m_lineHeight"];
         $message = $callerFunction . "|" .$callerValue;

         debug_to_console($message);
         serverSendData($message);
         debug_to_console("I am going to draw horizontal stripes.. :)");
      }
      function serverSend_DrawVerticalStripes()
      {
         $callerFunction = "VerticalStripes";
         $callerValue = $_POST["m_lineWidth"];
         $message = $callerFunction . "|" .$callerValue;

         debug_to_console($message);
         serverSendData($message);
         debug_to_console("I am going to draw vertical stripes.. :)");
      }
      function serverSend_DrawChessStripes()
      {
         $callerFunction = "ChessStripes";
         $callerValue = $_POST["m_squareSize"];
         $message = $callerFunction . "|" .$callerValue;

         debug_to_console($message);
         serverSendData($message);
         debug_to_console("I am going to draw Chess stripes.. :)");
      }

      function debug_to_console($data) {
          $output = $data;
          if (is_array($output))
              $output = implode(',', $output);
      
          echo "<script>console.log('Debug Objects: " . $output . "' );</script>";
      }

      function serverSendData($message)
      {
         $host    = "127.0.0.1";
         $port    = 6547;

         debug_to_console("Message To server :".$message);

         // create socket
         $socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("Could not create socket\n");
         // connect to server
         $result = socket_connect($socket, $host, $port) or die("Could not connect to server\n");  
         // send string to server
         socket_write($socket, $message, strlen($message)) or die("Could not send data to server\n");
         // get server response
         $result = socket_read ($socket, 1024) or die("Could not read server response\n");
         debug_to_console("Reply From Server  :".$result);
         // close socket
         socket_close($socket);
      }
      ?>
</html>

