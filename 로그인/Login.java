package 로그인;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.nio.channels.SocketChannel;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JButton;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import 메인.MainFrame;




//메인화면 Login 판넬
public class Login extends JFrame {
	String driver = "com.mysql.jdbc.Driver";
	String url = "jdbc:mysql://localhost:3306/survey";
	Connection con = null;
	PreparedStatement pstmt = null;								
	String sql;
	private ResultSet rs = null;
	
	private Login log;

	private JLabel lid, lpw; //아이디 비밀번호 라벨
	protected JTextField idTextField;// 아이디 입력 필드
	protected JPasswordField pwTextField;// 비밀번호 입력 필드
	
	protected JButton Ok;
	protected JButton Cancle;
	protected JButton Joining;
 

	String temp, id, pw; // 로그인 체크할 매개변수id,pw

	public boolean checklogin(String id, String pw) throws ClassNotFoundException {
		//로그인 체크하는 메소드
		try {
			Class.forName(driver);
			con = DriverManager.getConnection(url, "root", "apmsetup");
			sql = "select * from student_info where User_ID=? and User_Password=?";

			pstmt = con.prepareStatement(sql);

			pstmt.setString(1, idTextField.getText());
			pstmt.setString(2, pwTextField.getText());

			rs = pstmt.executeQuery();

			if (rs.next() == true) {
				
				JOptionPane.showMessageDialog(this, "로그인 성공");
				dispose();
				MainFrame M= new MainFrame( idTextField.getText());
				
				return true;
			}

			else if (rs.next() == false) {
				JOptionPane.showMessageDialog(this, "ID,PW 을 확인해주세요");
				idTextField.setText("");
				pwTextField.setText("");//id,pw 일치하지 않을 경우 id,pw 를 초기화시켜서 재입력을 받습니다
			}}catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;}

	private void loginstatus(String id2) {
		// TODO Auto-generated method stub
		
	}

	public Login() {
		JPanel p1 = new JPanel();
		JPanel p2 = new JPanel();
		JPanel p3 = new JPanel();
		
		this.setLayout(new BorderLayout());
		p1.setLayout(new FlowLayout());
		p2.setLayout(new FlowLayout());
		
		JLabel idLabel = new JLabel("ID                 :");
		idTextField = new JTextField(15);
		JLabel pwLabel = new JLabel("Password : ");
		pwTextField = new JPasswordField(15);
				
		setVisible(true);
		setSize(300,200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Ok = new JButton("확인");
		Cancle = new JButton("취소");
		Joining = new JButton("회원가입");
		this.add(BorderLayout.NORTH, p1);
		this.add(BorderLayout.CENTER, p2);
		this.add(BorderLayout.SOUTH, p3);
		p1.add(idLabel);
		p1.add(idTextField);
		p2.add(pwLabel);
		p2.add(pwTextField);
		p3.add(Ok);
		p3.add(Cancle);
		p3.add(Joining);
		Ok.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				try {
					checklogin(id, pw);// 로그인이 눌렸을 때에  로그인체크 메소드 실행
					
					
				} catch (ClassNotFoundException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();	}
			}
			});
		Cancle.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				dispose();}}
			);
		Joining.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				JoinForm jf = new JoinForm();}
			});
		}
		
	public static void main(String[] args) throws SQLException {

		Login login = new Login();

	}
}
