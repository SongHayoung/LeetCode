import java.io.UnsupportedEncodingException;
import java.util.Base64;
import java.util.LinkedList;
import java.util.List;

public class Codec {
final private String SYMBOL = ".";
    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for(String str : strs) {
            sb.append(encodeBase64(str));
            sb.append(SYMBOL);
        }
        return sb.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> res = new LinkedList<>();
        int index = 0, prev = 0;
        while(true) {
            index = s.indexOf(SYMBOL, index);
            if(index == -1)
                break;
            String subString = s.substring(prev, index);
            res.add(decodeBase64(subString));
            prev = ++index;
        }

        return res;
    }

    private String encodeBase64(String str) {
        String res = "";
        try {
            byte[] targetBytes = str.getBytes("UTF-8");
            Base64.Encoder encoder = Base64.getEncoder();

            byte[] encodedBytes = encoder.encode(targetBytes);
            res = encoder.encodeToString(targetBytes);
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } finally {
            return res;
        }
    }

    private String decodeBase64(String str) {
        Base64.Decoder decoder = Base64.getDecoder();

        byte[] targetBytes = decoder.decode(str);

        String res = "";
        try {
            res =  new String(targetBytes, "UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } finally {
            return res;
        }
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));
