6/2/2011  (c) Ether


SWERVE KINEMATIC CALCULATOR  for 4-wheel independently steered and driven swerve wheels.


Inverse Kinematics:  given a desired vehicle motion (fore/aft velocity, strafe velocity, and rotate velocity), calculate the wheel steering angle and the wheel tangential velocity for each of the 4 swerve wheels to produce that desired vehicle motion.  There is always a (unique) solution for the Inverse Kinematic problem for swerve.


Forward Kinematics:  given the wheel steering angle and wheel tangential velocity for each of the 4 swerve wheels, calculate what vehicle motion would result from that.  In general, there is no unique solution for the Forward Kinematic problem for arbitrarily chosen values for the 4 wheel steering angles and tangential velocities.  This calculator finds the "least squares" best-fit solution.  If the given values for the steering angle and tangential velocity of each of the 4 wheels actually correspond to a non-wheel-scrubbing vehicle motion (e.g. if the given values were actually computed correctly using inverse kinematics on a desired vehicle motion), then this calculator will find that vehicle motion solution.  Therefore, one use for forward kinematics is to check your inverse kinematic code.


Inverse Kinematics was covered in separate papers.

This paper covers forward kinematics.



Forward Kinematics has a solution IF the wheel speeds and angles were calculated (properly) from inverse kinematics.  That solution will be the original vehicle motions that were input to the inverse kinematics (if no normalization or clipping was done).


The forward kinematic solution is a least-squares solution and gives a "goodness of fit" parameter.  This tells you how "kinematically correct" your set of wheel speeds and angles is... in other words, how much (or how little) scrubbing will result.  The smaller the parameter the better the fit.  It's like the "correlation coefficient" you might remember from linear regression when fitting a line through a set of data points.


Read the discussion about forward kinematics (of mecanum) on the bottom of Page 7 and the top of Page 8 of this document:

http://www.chiefdelphi.com/media/papers/download/2722

In the case of swerve, the equations are not linear and it is not possible to use linear methods.  An iterative search is necessary to find the solution.  


The Computer Algebra System (CAS) Maxima is free and can be downloaded from SourceFore:  

http://maxima.sourceforge.net/


Files in this distribution:

README.txt                      the file you are now reading

swerveForwardKinematics.wxm     a ready-to-run wxMaxima document (wxMaxima is a Windows GUI interface to Maxima)

swerveForwardKinematics.pdf     the output from wxMaxima for the above WXM file

swerveForwardKinematics.mac     a Maxima "batch" (script) file which can be run in wxMaxima, or xMaxima, or Maxima









