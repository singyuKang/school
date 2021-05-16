package �α���;

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

import ����.MainFrame;




//����ȭ�� Login �ǳ�
public class Login extends JFrame {
	String driver = "com.mysql.jdbc.Driver";
	String url = "jdbc:mysql://localhost:3306/survey";
	Connection con = null;
	PreparedStatement pstmt = null;								
	String sql;
	private ResultSet rs = null;
	
	private Login log;

	private JLabel lid, lpw; //���̵� ��й�ȣ ��
	protected JTextField idTextField;// ���̵� �Է� �ʵ�
	protected JPasswordField pwTextField;// ��й�ȣ �Է� �ʵ�
	
	protected JButton Ok;
	protected JButton Cancle;
	protected JButton Joining;
 

	String temp, id, pw; // �α��� üũ�� �Ű�����id,pw

	public boolean checklogin(String id, String pw) throws ClassNotFoundException {
		//�α��� üũ�ϴ� �޼ҵ�
		try {
			Class.forName(driver);
			con = DriverManager.getConnection(url, "root", "apmsetup");
			sql = "select * from student_info where User_ID=? and User_Password=?";

			pstmt = con.prepareStatement(sql);

			pstmt.setString(1, idTextField.getText());
			pstmt.setString(2, pwTextField.getText());

			rs = pstmt.executeQuery();

			if (rs.next() == true) {
				
				JOptionPane.showMessageDialog(this, "�α��� ����");
				dispose();
				MainFrame M= new MainFrame( idTextField.getText());
				
				return true;
			}

			else if (rs.next() == false) {
				JOptionPane.showMessageDialog(this, "ID,PW �� Ȯ�����ּ���");
				idTextField.setText("");
				pwTextField.setText("");//id,pw ��ġ���� ���� ��� id,pw �� �ʱ�ȭ���Ѽ� ���Է��� �޽��ϴ�
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
		Ok = new JButton("Ȯ��");
		Cancle = new JButton("���");
		Joining = new JButton("ȸ������");
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
					checklogin(id, pw);// �α����� ������ ����  �α���üũ �޼ҵ� ����
					
					
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
