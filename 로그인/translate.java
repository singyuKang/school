package �α���;

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
		if (sex=="��")
			setUser_Sex("male");
		else 
			setUser_Sex("female");
	}
	public void Gradetrans(String grade) {
		if(grade=="1�г�")
			User_Grade="freshman";
		else if (grade=="2�г�")
			User_Grade="sophomore";
		else if (grade=="3�г�")
			User_Grade="junior";
		else
			User_Grade="senior";
	
	}
	public void Classtrans(String Class) {
		if(Class=="��ȣ����")
			User_Class="Nursing";
		else if (Class=="��������")
			User_Class="Engineering";
		else if (Class=="���������к�")
			User_Class="Public Talents";
		else if (Class=="���������д���")
			User_Class="Agriculture Sciences";
		else if (Class=="�������")
			User_Class="Education";
		else if (Class=="��ȸ���д���")
			User_Class="Social Science";
		else if (Class=="�������")
			User_Class="Commerce";
		else if (Class=="��Ȱ���д���")
			User_Class="Life Science";
		else if (Class=="��������")
			User_Class="Arts";
		else if (Class=="�ι�����")
			User_Class="Humanities";
		else if (Class=="�ǰ�����")
			User_Class="Medical";
		else if (Class=="�ڿ����д���")
			User_Class="Natural Science";
		else if (Class=="ġ������")
			User_Class="dentistry";

	}
	public String getUser_Sex() {
		return User_Sex;
	}
	public void setUser_Sex(String user_Sex) {
		User_Sex = user_Sex;
	}
	

}
