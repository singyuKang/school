package 로그인;

public class translate {
	private String User_ID;
	private String User_Password;
	private String User_Sex;
	public String getUser_ID() {
		return User_ID;
	}
	public void setUser_ID(String user_ID) {
		User_ID = user_ID;
	}
	public String getUser_Password() {
		return User_Password;
	}
	public void setUser_Password(String user_Password) {
		User_Password = user_Password;
	}
	private String User_Grade;
	private String User_Class;
	
	
	public translate(String User_ID,String User_Password,String user_Sex, String user_Grade, String user_Class) {
		this.User_ID= User_ID;
		this.User_Password=User_Password;
		this.setUser_Sex(user_Sex);
		this.User_Grade=user_Grade;
		this.User_Class=user_Class;
		Sextrans(this.getUser_Sex());
		Gradetrans(this.getUser_Grade());
		Classtrans(this.getUser_Class());
		// TODO Auto-generated constructor stub
	}
	public String getUser_Grade() {
		return User_Grade;
	}
	public void setUser_Grade(String user_Grade) {
		User_Grade = user_Grade;
	}
	public String getUser_Class() {
		return User_Class;
	}
	public void setUser_Class(String user_Class) {
		User_Class = user_Class;
	}
	public void Sextrans(String sex) {
		if (sex=="남")
			setUser_Sex("male");
		else 
			setUser_Sex("female");
	}
	public void Gradetrans(String grade) {
		if(grade=="1학년")
			User_Grade="freshman";
		else if (grade=="2학년")
			User_Grade="sophomore";
		else if (grade=="3학년")
			User_Grade="junior";
		else
			User_Grade="senior";
	
	}
	public void Classtrans(String Class) {
		if(Class=="간호대학")
			User_Class="Nursing";
		else if (Class=="공과대학")
			User_Class="Engineering";
		else if (Class=="공공인재학부")
			User_Class="Public Talents";
		else if (Class=="농업생명과학대학")
			User_Class="Agriculture Sciences";
		else if (Class=="사범대학")
			User_Class="Education";
		else if (Class=="사회과학대학")
			User_Class="Social Science";
		else if (Class=="상과대학")
			User_Class="Commerce";
		else if (Class=="생활과학대학")
			User_Class="Life Science";
		else if (Class=="예술대학")
			User_Class="Arts";
		else if (Class=="인문대학")
			User_Class="Humanities";
		else if (Class=="의과대학")
			User_Class="Medical";
		else if (Class=="자연과학대학")
			User_Class="Natural Science";
		else if (Class=="치과대학")
			User_Class="dentistry";

	}
	public String getUser_Sex() {
		return User_Sex;
	}
	public void setUser_Sex(String user_Sex) {
		User_Sex = user_Sex;
	}
	

}
