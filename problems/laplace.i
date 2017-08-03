[Mesh]
  type = GeneratedMesh # Can generate simple lines, rectangles and rectangular prisms
  dim = 2 # Dimension of the mesh
  nx = 10 # Number of elements in the x direction
  ny = 10 # Number of elements in the y direction

[]
[Variables]
  [./u]
    #Adds a Linear Lagrange variable by default
  [../]
[]
[Kernels]
  [./diff]
    type = Diffusion # A Laplacian operator
    variable = u # Operate on the
  [../]
[]
[BCs]
  [./bottom]
    type = DirichletBC # Simple u=value BC
    variable = u
    boundary = bottom # Name of a sideset in the mesh
    value = 10
  [../]

   [./top]
    type = DirichletBC # Simple u=value BC
    variable = u
    boundary = top # Name of a sideset in the mesh
    value = 20
  [../]


   [./left]
    type = DirichletBC # Simple u=value BC
    variable = u
    boundary = left # Name of a sideset in the mesh
    value = 20
  [../]

 [./right]
    type = DirichletBC # Simple u=value BC
    variable = u
    boundary = right # Name of a sideset in the mesh
    value = 10
  [../]


[]

[Materials]
  [./mat]
    type = LYMaterial
    block = 0
    ly_u = u
    kappa = 1
  [../]
[]

[Executioner]
  type = Steady # Steady state problem
  petsc_options_iname = '-pc_type -pc_hypre_type' #Matches with the values below
  petsc_options_value = 'hypre boomeramg'
[]
[Outputs]
  exodus = true # Output Exodus format
[]
