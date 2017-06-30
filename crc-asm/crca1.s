.global crcInit
.global crcFast
.text
crcInit:
	# LOOP1 in crcInit
	movl 	$0, %edi					# Assign dividend = 0
  movq 	$crcTable, %rcx		# Take the address of crcTable
.LOOP: # Compute the remainder of each possible dividend
	movb 	%dil, %sil 				# Assign remainder = Dividend
	movb 	$8, %dl						# Set bit = 8

.INNER_LOOP: # Perform module-2 division, a bit at a time

	movb 	%sil, %al					# Assign value of remainder to register %al (8 bit)
	andb	$0x80, %al				# Compute remainder & 0x80
	cmpb 	$0x80, %al				# compare to test if (remainder & 0x80)
	je 		.IF							  # if equal 0, go to .IF
	salb	$1, %sil					# else, remainder = (remainder << 1)
	jmp 	.EXIT_INNER				# Go check inner loop

.IF: # Equal
	salb 	$1, %sil					# remainder = (remainder << 1) ^ 0xD5
	xorb 	$0xD5, %sil       # xor remainder with 0xD5


.EXIT_INNER:
  subb 	$1, %dl						# decrement bit by 1
	cmpb 	$0, %dl						# check if bit is greater than 0
	jg		.INNER_LOOP				# if yes, go back to INNER LOOP

	# Store the result into the table
	movb	%sil, (%rcx, %rdi)# store value of remainder to crcTable
	addl 	$1, %edi					# Increase dividend
	cmpl	$256, %edi				# check if dividend is less than 256
	jl	 	.LOOP						  # if yes, go back to LOOP
	ret									    # return


crcFast:
	movb 	$0, %al						# Assign remainder = 0
	movq 	$0, %rdx					# Assign long byte = 0
  movq 	$crcTable, %r8		# get the address of crcTable

	# LOOP in crcFast
.LOOP_FAST:
	movb 	%al, %cl					    # Assign value of remainder to %cl
	xorb 	(%rdx, %rdi), %cl			# data = message[byte] ^ remainder
	andq 	$0xFF,%rcx 	          # mask the 15 upper bytes to take 8 bits

	movb 	(%r8, %rcx), %al			# remainder = crcTable[data]

	addq	$1, %rdx					    # increase byte by 1
	cmpq 	%rsi, %rdx					  # check if byte is less than nBytes
	jl		.LOOP_FAST						# if yes, go back to .LOOP_FAST
	ret									        # return


.data                     #directive data
crcTable:	.rept 256       # crcTable and hold 256 byte
			.byte 0x00          # initial 0 value
			.endr               # end crcTable
