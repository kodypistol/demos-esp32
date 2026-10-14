import { SerialPort } from "serialport";
import { WebSocketServer } from "ws";

const esp32 = new SerialPort({
  path: "/dev/cu.usbserial-A5069RR4",
  baudRate: 115200,
});
const server = new WebSocketServer({ port: 8080 });

server.on("connection", (page) => {
  page.on("message", (message) => {
    console.log("page ->", message.toString());
    esp32.write(message.toString() + "\n");
  });
});
