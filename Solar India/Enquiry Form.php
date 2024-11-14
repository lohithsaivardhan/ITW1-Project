<!doctype html>
<html class="no-js" lang="zxx">
    <head>
		<meta charset="utf-8">
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<meta name="keywords" content="Site keywords here">
		<meta name="description" content="">
		<meta name='copyright' content=''>
		<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <title>Enquiry Form</title>
        <link href="https://fonts.googleapis.com/css?family=Poppins:200i,300,300i,400,400i,500,500i,600,600i,700,700i,800,800i,900,900i&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <link rel="stylesheet" href="css/normalize.css">
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="css/responsive.css">
    </head>
    <body>
		<header class="header">
			<div class="header-inner">
				<div class="container">
					<div class="inner">
						<div class="row">
							<div class="col-lg-3 col-md-3 col-12">
								<div class="logo">
									<a href="Home Page.html"><img src="new_logo.jpg" alt="#"></a>
								</div>
								<div class="mobile-nav"></div>
							</div>
							<div class="col-lg-7 col-md-9 col-12">
								<div class="main-menu">
									<nav class="navigation">
										<ul class="nav menu">
											<li class="active"><a href="Home Page.html">Home</a></li>
											<li><a href="https://pmsuryaghar.gov.in/rooftop_calculator">Solar Calculator </a></li>
											<li><a href="Schemes.html">Government Schemes</i></a>
												<ul class="dropdown">
													<li><a href="PM Surya Ghar.html">PM Surya Ghar</a></li>
                                                    <li><a href="PLI Scheme.html">PLI Scheme</a></li>
													<li><a href="PM KUSUM Scheme.html">PM KUSUM</a></li>
												</ul>
											</li>
                                            <li class="active"><a href="Acknowledgement.html">Acknowledgement</a></li>
										</ul>
									</nav>
								</div>
							</div>
							<div class="col-lg-2 col-12">
								<div class="get-quote">
									<a href="Enquiry Form.php" class="btn">Enquiry Form</a>
								</div>
							</div>
						</div>
					</div>
				</div>
			</div>
		</header>
		<script>
			function mssg(){
				alert("Your response has been sent successfully, you would receive a reply from us soon..");
			}
		</script>
		<section class="contact-us section">
			<div class="container">
				<div class="inner">
					<div class="row">
						<div class="col-lg-6">
							<div class="contact-us-form">
								<h2>Enquiry Form</h2>
								<p>Please fill the form and we will get back to you</p>
								<form class="form" onsubmit="mssg()" action="#" method="post">
									<div class="row">
										<div class="col-lg-6">
											<div class="form-group">
												<input type="text" name="name" placeholder="First Name" required="">
											</div>
										</div>
										<div class="col-lg-6">
											<div class="form-group">
												<input type="text" name="lname" placeholder="Last Name" required="">
											</div>
										</div>
										<div class="col-lg-6">
											<div class="form-group">
												<input type="email" name="email" placeholder="Email" required="">
											</div>
										</div>
										<div class="col-lg-6">
											<div class="form-group">
												<input type="text" name="phone" placeholder="Phone" required="">
											</div>
										</div>
										<div class="col-lg-6">
											<div class="form-group">
												<input type="text" name="subject" placeholder="State" required="">
											</div>
										</div>
										<div class="col-lg-6">
											<div class="form-group">
												<input type="text" name="subject" placeholder="City/Town" required="">
											</div>
										</div>
										<div class="col-lg-6">
											<div class="form-group">
												<input type="text" name="subject" placeholder="Subject" required="">
											</div>
										</div>
										<div class="col-lg-12">
											<div class="form-group">
												<textarea name="message" placeholder="Your Message" required=""></textarea>
											</div>
										</div>
										<div class="col-12">
											<div class="form-group login-btn">
												<button class="btn"><a href="Terms.html" target="_blank">Terms of Use and Agreement</a><br></button>
											</div>
										</div>
										<br>
										<div class="col-lg-6">
											<div class="form-group">
												
											</div>
										</div>
										<div class="col-12">
    <div class="form-group login-btn">
        <input type="submit" name="submit" class="btn" style="background-color: rgb(250, 6, 6); color: white;">
    </div>
</div>

									</div>
								</form>
							</div>
						</div>
					</div>
				</div>
			</div>
		</section>
		<video width=100% autoplay loop muted>
            <source src="video.mp4" type="video/mp4">
            Your browser does not support the video tag.
          </video>
		
    </body>
</html>

<?php
use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\SMTP;
use PHPMailer\PHPMailer\Exception;

require 'PHPMailer/Exception.php';
require 'PHPMailer/PHPMailer.php';
require 'PHPMailer/SMTP.php';

if (isset($_POST["submit"])) {
    $name = $_POST['name'];
    $email = $_POST['email'];

    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        echo "Invalid email format";
        exit;
    }

    $name = htmlspecialchars($name, ENT_QUOTES);
    $email = filter_var($email, FILTER_SANITIZE_EMAIL);
    

    $mail = new PHPMailer(true);
    try {
        $mail->isSMTP();
        $mail->Host = 'smtp.gmail.com';
        $mail->SMTPAuth = true;
        $mail->Username = 'solarindia021@gmail.com';
        $mail->Password = 'vffp zsdi tphx ubmz';
        $mail->SMTPSecure = PHPMailer::ENCRYPTION_SMTPS;
        $mail->Port = 465;

        $mail->setFrom($email, 'Solar India');
        $mail->addAddress($_POST['email'], $name);

        $mail->isHTML(true);    
        $mail->Subject = 'Response to Enquiry Form';
        $mail->Body = "Dear $name,<br><br>
		Thanks for your interest in solar! We received your inquiry about"." ". $_POST['subject'].".<br><br>
		Please refer the below link for the details :<br>
		https://drive.google.com/file/d/1dlKH_b9tTCEJfVh1QdGCFItbUsL2Nke4/view?usp=sharing
		<br><br>We offer free consultations to discuss your needs and recommend the best solution. Reply to schedule one, call us at <a>+91 9848350956</a>.
		<br><br>Let's brighten your future with solar power!
		
		<br><br>Sincerely,
		<br><br>
		Team Solar India";

        $mail->send();
        echo 'Message has been sent';
    } catch (Exception $e) {
        echo "Message could not be sent. Mailer Error: {$mail->ErrorInfo}";
    }
}
?>
