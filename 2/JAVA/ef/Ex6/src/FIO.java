public class FIO {
    public static void verification(String Fio) throws FioException {
        String[] parts = Fio.split(" ");
        if (parts.length != 3) {
            throw new FioException("ФИО должно состоять из 3 слов");
        }
        for (int i = 0; i < parts.length; i++) {
            String part = parts[i];
            if (part.length() < 3 || part.length() > 15) {
                throw new FioException("Слово в ФИО должно содержать не менее 3-х и не более 15-и символов");
            }
            if (!Character.isUpperCase(part.charAt(0))) {
                throw new FioException("Первая буква каждого слова должна быть заглавной");
            }
            if (!part.substring(1).matches("[а-я]*")) {
                throw new FioException("Слова должны содержать только прописные буквы");
            }
            for (int j = 0; j < parts.length; j++) {
                if (i != j && part.equalsIgnoreCase(parts[j])) {
                    throw new FioException("Все три слова должны быть попарно различны");
                }
            }
        }
    }
    static class FioException extends Exception {
        public FioException(String m) {
            super(m);
        }
    }
}

