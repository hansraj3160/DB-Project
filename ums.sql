-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Aug 03, 2020 at 09:47 PM
-- Server version: 10.1.38-MariaDB
-- PHP Version: 7.3.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `ums`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `feestatus` (IN `cms` INT, OUT `checkstatus` VARCHAR(20))  BEGIN
 DECLARE totals  DECIMAL DEFAULT 0;
 SELECT Total
 INTO totals
 FROM fees
 WHERE ID = cms;
 IF totals > 10700 THEN
 SET checkstatus = 'Paid';
 ELSE
 SET checkstatus ="not full paid";
 END IF;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `user_name` varchar(23) NOT NULL,
  `PASSWORD` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`user_name`, `PASSWORD`) VALUES
('admin', '123');

-- --------------------------------------------------------

--
-- Table structure for table `course`
--

CREATE TABLE `course` (
  `courseID` int(20) NOT NULL,
  `title` varchar(100) NOT NULL,
  `credit` int(20) DEFAULT NULL,
  `inst_ID` int(20) NOT NULL,
  `dep_ID` int(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `course`
--

INSERT INTO `course` (`courseID`, `title`, `credit`, `inst_ID`, `dep_ID`) VALUES
(1, 'Database Managment System', 4, 100, 101),
(2, 'Operating system', 4, 103, 101),
(4, 'Organizational Behaviour', 3, 105, 101),
(5, 'Software Engineering Required', 3, 111, 102);

-- --------------------------------------------------------

--
-- Table structure for table `department`
--

CREATE TABLE `department` (
  `dep_ID` int(8) NOT NULL,
  `dep_name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `department`
--

INSERT INTO `department` (`dep_ID`, `dep_name`) VALUES
(103, 'BE-Computer System'),
(106, 'BE-Electrical Engineer'),
(105, 'BS-Artificial Intelligence'),
(101, 'BS-Computer Science'),
(102, 'BS-Software Eengineering');

-- --------------------------------------------------------

--
-- Table structure for table `enrollment`
--

CREATE TABLE `enrollment` (
  `enroll_id` int(20) NOT NULL,
  `ID` int(20) NOT NULL,
  `courseID` int(20) NOT NULL,
  `credit` int(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `enrollment`
--

INSERT INTO `enrollment` (`enroll_id`, `ID`, `courseID`, `credit`) VALUES
(1, 1, 1, 4),
(2, 1, 2, 4),
(4, 1, 4, 3),
(5, 2, 5, 4),
(7, 3, 2, 4);

-- --------------------------------------------------------

--
-- Table structure for table `fees`
--

CREATE TABLE `fees` (
  `Recipt` int(20) NOT NULL,
  `tutionfee` int(20) NOT NULL,
  `LibraryFees` int(20) NOT NULL,
  `SECURITYFees` int(20) NOT NULL,
  `Total` int(20) NOT NULL,
  `S_id` int(20) DEFAULT NULL,
  `status` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `fees`
--

INSERT INTO `fees` (`Recipt`, `tutionfee`, `LibraryFees`, `SECURITYFees`, `Total`, `S_id`, `status`) VALUES
(1, 10000, 500, 200, 10700, 1, 1),
(2, 10000, 500, 200, 10700, 2, 1),
(3, 10000, 500, 200, 10700, 3, 1),
(4, 10000, 0, 200, 10200, 4, 0),
(5, 10000, 500, 0, 10500, 5, 0),
(6, 10000, 500, 20, 10520, 6, 1);

-- --------------------------------------------------------

--
-- Table structure for table `instructor`
--

CREATE TABLE `instructor` (
  `inst_ID` int(20) NOT NULL,
  `FIRST_name` varchar(20) DEFAULT NULL,
  `LAST_name` varchar(20) DEFAULT NULL,
  `dep_ID` int(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `instructor`
--

INSERT INTO `instructor` (`inst_ID`, `FIRST_name`, `LAST_name`, `dep_ID`) VALUES
(100, 'MR', 'Khalid', 101),
(101, 'Dr.Ahmed', 'Waqas', 101),
(102, 'Dr.Irfan', 'Hyder', 101),
(103, 'ali', 'khan', 106),
(104, 'Adnan', 'ruff', 101),
(105, 'Dr.Abdul', 'Basit', 101),
(106, 'Dr.javeed', 'Sidique', 102),
(107, 'Irfan', 'Hyder', 103),
(108, 'Irfan', 'Hyder', 103),
(110, 'Arfan', 'Queshi', 105),
(111, 'Asim', 'Bhuto', 102);

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE `student` (
  `ID` int(20) NOT NULL,
  `fname` varchar(40) NOT NULL,
  `lname` varchar(40) NOT NULL,
  `dep_ID` int(40) NOT NULL,
  `age` int(11) NOT NULL,
  `phone` varchar(40) NOT NULL,
  `email` varchar(40) NOT NULL,
  `address` varchar(100) NOT NULL,
  `Date` timestamp(6) NOT NULL DEFAULT CURRENT_TIMESTAMP(6)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`ID`, `fname`, `lname`, `dep_ID`, `age`, `phone`, `email`, `address`, `Date`) VALUES
(1, 'Hans', 'Raj', 103, 20, '3023272316', 'rajh@gmail.com', 'Kunri', '2020-07-28 19:00:00.000000'),
(2, 'Zeeshan', 'Ahmed', 101, 19, '3023232435', 'Zeeshanahmed@gmail.com', 'Larkana', '2020-07-29 04:58:30.386557'),
(3, 'Noman', 'Ahmed', 101, 32, '3023232453', 'nomanahmed@gmail.com', 'nawabshah', '2020-07-29 04:58:30.433430'),
(4, 'Samad', 'Ahmed', 103, 18, '3023232435', 'samadahmed@gmail.com', 'sukkur', '2020-07-29 04:58:30.630667'),
(5, 'Masooma', 'tareeq', 101, 27, '3023233222', 'Mahanoor@gmail.com', 'shikarpure', '2020-07-29 04:58:30.599421'),
(6, 'jai', 'Mala', 103, 24, '3023243532', 'jaimala.bcsf18@iba-suk.edu.pk', 'kunri pak', '2020-07-29 04:58:30.495928'),
(8, 'Rizwan', 'Bukhari', 102, 22, '3023234233', 'rizwanbukhari@gmail.com', 'Nosheroferoz', '2020-08-03 07:09:08.402514'),
(9, 'Dheeraj', 'parkash', 103, 19, '303232344', 'dheerajparkash@gmail.com', 'dharki sindh', '2020-08-03 13:35:29.924664'),
(10, 'faizan', 'Kuku', 102, 20, '32032433', 'faizan@gmail.com', 'sukkur sindh', '2020-08-03 16:27:58.682074');

-- --------------------------------------------------------

--
-- Stand-in structure for view `studentlogin`
-- (See below for the actual view)
--
CREATE TABLE `studentlogin` (
`user_name` varchar(60)
,`PASSWORD` varchar(40)
);

-- --------------------------------------------------------

--
-- Structure for view `studentlogin`
--
DROP TABLE IF EXISTS `studentlogin`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `studentlogin`  AS  select concat(`student`.`fname`,`student`.`ID`) AS `user_name`,`student`.`lname` AS `PASSWORD` from `student` ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `course`
--
ALTER TABLE `course`
  ADD PRIMARY KEY (`courseID`),
  ADD KEY `dep_ID` (`dep_ID`),
  ADD KEY `foreign Key` (`inst_ID`);

--
-- Indexes for table `department`
--
ALTER TABLE `department`
  ADD PRIMARY KEY (`dep_ID`),
  ADD UNIQUE KEY `UNIQUE` (`dep_name`);

--
-- Indexes for table `enrollment`
--
ALTER TABLE `enrollment`
  ADD PRIMARY KEY (`enroll_id`),
  ADD KEY `fk_id` (`ID`),
  ADD KEY `fk_courseid` (`courseID`);

--
-- Indexes for table `fees`
--
ALTER TABLE `fees`
  ADD PRIMARY KEY (`Recipt`),
  ADD KEY `S_id` (`S_id`);

--
-- Indexes for table `instructor`
--
ALTER TABLE `instructor`
  ADD PRIMARY KEY (`inst_ID`),
  ADD KEY `FK_Department` (`dep_ID`);

--
-- Indexes for table `student`
--
ALTER TABLE `student`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `dep_ID` (`dep_ID`) USING BTREE;

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `course`
--
ALTER TABLE `course`
  MODIFY `courseID` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `enrollment`
--
ALTER TABLE `enrollment`
  MODIFY `enroll_id` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `fees`
--
ALTER TABLE `fees`
  MODIFY `Recipt` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `instructor`
--
ALTER TABLE `instructor`
  MODIFY `inst_ID` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=112;

--
-- AUTO_INCREMENT for table `student`
--
ALTER TABLE `student`
  MODIFY `ID` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `course`
--
ALTER TABLE `course`
  ADD CONSTRAINT `course_ibfk_1` FOREIGN KEY (`dep_ID`) REFERENCES `department` (`dep_ID`) ON UPDATE CASCADE;

--
-- Constraints for table `enrollment`
--
ALTER TABLE `enrollment`
  ADD CONSTRAINT `fk_courseid` FOREIGN KEY (`courseID`) REFERENCES `course` (`courseID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `fk_id` FOREIGN KEY (`ID`) REFERENCES `student` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `fees`
--
ALTER TABLE `fees`
  ADD CONSTRAINT `fees_ibfk_1` FOREIGN KEY (`S_id`) REFERENCES `student` (`ID`);

--
-- Constraints for table `instructor`
--
ALTER TABLE `instructor`
  ADD CONSTRAINT `FK_Department` FOREIGN KEY (`dep_ID`) REFERENCES `department` (`dep_ID`) ON DELETE CASCADE;

--
-- Constraints for table `student`
--
ALTER TABLE `student`
  ADD CONSTRAINT `student_ibfk_1` FOREIGN KEY (`dep_ID`) REFERENCES `department` (`dep_ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
