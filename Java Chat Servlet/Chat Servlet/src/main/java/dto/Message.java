package dto;

public class Message {
    private String room_no;
    private String username;
    private String date;
    private String message;

    public Message(String room_no, String username, String date, String message) {
        this.room_no = room_no;
        this.username = username;
        this.date = date;
        this.message = message;
    }

    public String getRoom_no() {
        return room_no;
    }

    public void setRoom_no(String room_no) {
        this.room_no = room_no;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }
}
