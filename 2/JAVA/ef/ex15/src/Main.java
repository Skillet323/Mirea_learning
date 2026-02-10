import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpServer;

import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.util.Map;

public class Main {

    private static final int PORT = 2929;
    private static final String INFO = "Усачев Иван Алексеевич";

    public static void main(String[] args) throws IOException {
        System.out.println(INFO);

        HttpServer server = HttpServer.create(new InetSocketAddress(PORT), 0);
        server.createContext("/convert", new ConvertHandler());
        server.setExecutor(null);
        System.out.println("Сервер запущен на порту " + PORT);
        System.out.println("URL для проверки:");
        System.out.println("http://localhost:2929/convert?value=100&from=meters&to=kilometers");
        System.out.println("http://localhost:2929/convert?value=500&from=grams&to=kilograms");
        System.out.println("http://localhost:2929/convert?value=32&from=fahrenheit&to=celsius\n");
        server.start();
    }

    static class ConvertHandler implements HttpHandler {
        @Override
        public void handle(HttpExchange exchange) throws IOException {
            if (!"GET".equals(exchange.getRequestMethod())) {
                sendResponse(exchange, 405, "Метод не поддерживается");
                return;
            }
            Map<String, String> queryParams = parseQuery(exchange.getRequestURI().getQuery());
            try {
                double value = Double.parseDouble(queryParams.get("value"));
                String from = queryParams.get("from");
                String to = queryParams.get("to");
                double result = convert(value, from, to);
                sendResponse(exchange, 200, String.valueOf(result));
            } catch (Exception e) {sendResponse(exchange, 400,
                    "Неверный запрос: " + e.getMessage());}
        }
        private double convert(double value, String from, String to) {
            switch (from + "_to_" + to) {
                case "meters_to_kilometers":
                    return value / 1000;
                case "kilometers_to_meters":
                    return value * 1000;
                case "grams_to_kilograms":
                    return value / 1000;
                case "kilograms_to_grams":
                    return value * 1000;
                case "celsius_to_fahrenheit":
                    return (value * 9 / 5) + 32;
                case "fahrenheit_to_celsius":
                    return (value - 32) * 5 / 9;
                default:
                    throw new IllegalArgumentException("Неподдерживаемое преобразование: " + from + " в " + to);
            }
        }
        private Map<String, String> parseQuery(String query) {
            return Map.of(query.split("&")[0].split("=")[0], query.split("&")[0].split("=")[1],
                    query.split("&")[1].split("=")[0], query.split("&")[1].split("=")[1],
                    query.split("&")[2].split("=")[0], query.split("&")[2].split("=")[1]);
        }
        private void sendResponse(HttpExchange exchange, int statusCode, String response) throws IOException {
            String fullResponse = response + "\nUsachev Ivan Alekseevich 0240";
            exchange.sendResponseHeaders(statusCode, fullResponse.getBytes("UTF-8").length);
            OutputStream os = exchange.getResponseBody();
            os.write(fullResponse.getBytes("UTF-8"));
            os.close();
        }
    }
}
